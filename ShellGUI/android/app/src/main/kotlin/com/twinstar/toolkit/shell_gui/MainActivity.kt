package com.twinstar.toolkit.shell_gui

import android.Manifest
import android.content.Intent
import android.content.pm.PackageManager
import android.net.Uri
import android.os.Build
import android.os.Bundle
import android.os.Environment
import android.provider.OpenableColumns
import android.provider.Settings
import io.flutter.embedding.android.FlutterActivity
import io.flutter.embedding.engine.FlutterEngine
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugins.GeneratedPluginRegistrant
import java.io.File
import java.io.FileOutputStream

class MainActivity: FlutterActivity() {

	override fun onCreate(savedInstanceState: Bundle?) {
		super.onCreate(savedInstanceState)
		this.command = listOf()
		if (this.intent.action == "${this.packageName}.action.LAUNCH") {
			this.command = this.intent.extras!!.getStringArray("command")!!.toList()
		}
		return
	}

	override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
		super.onActivityResult(requestCode, resultCode, data)
		when (requestCode) {
			REQUEST_STORAGE_PERMISSION -> {
				this.checkStoragePermission()
			}
			REQUEST_PICK_PATH -> {
				var path = data?.data?.let { this.parsePathOfContentProviderUri(it, this.fallbackDirectoryWhenPickPath) ?: it.toString() }
				this.methodResult.success(path)
			}
			else -> {
			}
		}
		return
	}

	override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
		super.onRequestPermissionsResult(requestCode, permissions, grantResults)
		when (requestCode) {
			REQUEST_STORAGE_PERMISSION -> {
				this.checkStoragePermission()
			}
			else -> {
			}
		}
		return
	}

	override fun configureFlutterEngine(flutterEngine: FlutterEngine) {
		GeneratedPluginRegistrant.registerWith(flutterEngine)
		MethodChannel(flutterEngine.dartExecutor.binaryMessenger, "${this.packageName}.flutter_method_channel")
			.setMethodCallHandler { call, result ->
				this.methodResult = result
				when (call.method) {
					"checkStoragePermission" -> {
						this.checkStoragePermission()
					}
					"requestStoragePermission" -> {
						this.requestStoragePermission()
					}
					"getCommand" -> {
						var fallbackDirectory = call.argument<String>("fallbackDirectory")
						this.getCommand(fallbackDirectory)
					}
					"pickPath" -> {
						var typeIsDirectory = call.argument<Boolean>("typeIsDirectory")!!
						var fallbackDirectory = call.argument<String>("fallbackDirectory")
						this.pickPath(typeIsDirectory, fallbackDirectory)
					}
					else -> result.notImplemented()
				}
			}
		return
	}

	private fun checkStoragePermission(): Unit {
		var state: Boolean
		if (Build.VERSION.SDK_INT < Build.VERSION_CODES.R) {
			state = this.checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED &&
					this.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED
		}
		else {
			state = Environment.isExternalStorageManager()
		}
		this.methodResult.success(state)
		return
	}

	private fun requestStoragePermission(): Unit {
		if (Build.VERSION.SDK_INT < Build.VERSION_CODES.R) {
			this.requestPermissions(arrayOf(Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE), REQUEST_STORAGE_PERMISSION)
		}
		else {
			this.startActivityForResult(Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION, Uri.parse("package:${this.packageName}")), REQUEST_STORAGE_PERMISSION)
		}
		return
	}

	private fun getCommand(fallbackDirectory: String?): Unit {
		this.methodResult.success(this.command.map { if (!it.startsWith("content://")) (it) else (this.parsePathOfContentProviderUri(Uri.parse(it), fallbackDirectory) ?: it) })
		return
	}

	private fun pickPath(typeIsDirectory: Boolean, fallbackDirectory: String?): Unit {
		this.fallbackDirectoryWhenPickPath = fallbackDirectory
		var intent = Intent(if (!typeIsDirectory) (Intent.ACTION_GET_CONTENT) else (Intent.ACTION_OPEN_DOCUMENT_TREE)).also {
			it.putExtra(Intent.EXTRA_LOCAL_ONLY, true)
			if (!typeIsDirectory) {
				it.addCategory(Intent.CATEGORY_OPENABLE)
				it.setType("*/*")
			}
		}
		this.startActivityForResult(intent, REQUEST_PICK_PATH)
		return
	}

	private fun parsePathOfContentProviderUri(uri: Uri, fallbackDirectory: String?): String? {
		var result = null as String?
		var provider = uri.authority!!
		var path = uri.path!!
		when (provider) {
			// AOSP DocumentsUI
			"com.android.externalstorage.documents" -> {
				// /tree/primary:<path-relative-external-storage>
				if (path.startsWith("/tree/primary:")) {
					result = "${Environment.getExternalStorageDirectory().path}${path.substring("/tree/primary:".length).let { if (it.isEmpty()) (it) else ("/${it}") }}"
				}
				// /document/primary:<path-relative-external-storage>
				if (path.startsWith("/document/primary:")) {
					result = "${Environment.getExternalStorageDirectory().path}${path.substring("/document/primary:".length).let { if (it.isEmpty()) (it) else ("/${it}") }}"
				}
			}
			"com.android.providers.media.documents" -> {
				// /document/document:<id>
				// /document/image:<id>
				// /document/audio:<id>
				// /document/video:<id>
			}
			"com.android.providers.downloads.documents" -> {
				// /document/raw:<path-absolute>
				if (path.startsWith("/document/raw:")) {
					result = "${path.substring("/document/raw:".length)}"
				}
				// /document/msf:<id>
			}
			// Material Files
			"me.zhanghai.android.files.file_provider" -> {
				path = Uri.decode(path)
				// /file://<path-absolute>
				if (path.startsWith("/file://")) {
					result = "${Uri.parse(path.substring("/".length)).path!!}"
				}
			}
			// Explorer
			"com.speedsoftware.explorer.fileprovider",
			// Root Explorer
			"com.speedsoftware.rootexplorer.fileprovider" -> {
				// /root/<path-relative-root>
				if (path.startsWith("/root/")) {
					result = "/${path.substring("/root/".length)}"
				}
			}
			// Solid Explorer
			"pl.solidexplorer2.files",
			// MT Manager
			"bin.mt.plus.fp",
			// NMM
			"in.mfile.files" -> {
				// <path-absolute>
				result = path
			}
			else -> {
				if (path.startsWith("/") && File(path).exists()) {
					result = path
				}
			}
		}
		if (result == null && fallbackDirectory != null) {
			var fallbackName = this.queryDatabaseOfContentProviderUri(uri, OpenableColumns.DISPLAY_NAME) ?: uri.lastPathSegment
			if (fallbackName != null) {
				var fallbackFile = "${fallbackDirectory}/${fallbackName}"
				if (this.copyFileOfContentProviderUri(uri, fallbackFile)) {
					result = fallbackFile
				}
			}
		}
		return result
	}

	private fun queryDatabaseOfContentProviderUri(uri: Uri, name: String): String? {
		var value = null as String?
		try {
			val cursor = this.contentResolver.query(uri, arrayOf(name), null, null, null, null)
			if (cursor != null) {
				if (cursor.moveToFirst() && cursor.columnCount == 1) {
					value = cursor.getString(0)
				}
				cursor.close()
			}
		}
		catch (e: Exception) {
		}
		return value
	}

	private fun copyFileOfContentProviderUri(uri: Uri, path: String): Boolean {
		var state = false
		try {
			this.contentResolver.openInputStream(uri)!!.use { input ->
				FileOutputStream(path, false).use { output ->
					input.copyTo(output)
				}
			}
			state = true
		}
		catch (e: Exception) {
		}
		return state
	}

	private lateinit var methodResult: MethodChannel.Result

	private lateinit var command: List<String>

	private var fallbackDirectoryWhenPickPath: String? = null

	companion object {

		private const val REQUEST_STORAGE_PERMISSION: Int = 1001

		private const val REQUEST_PICK_PATH: Int = 1002

	}

}
