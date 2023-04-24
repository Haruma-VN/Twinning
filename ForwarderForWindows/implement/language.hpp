#pragma once

#include "implement/common.hpp"

namespace TwinStar::ForwarderForWindows::Language {

	#pragma region constant

	inline auto const g_table = std::unordered_map<std::wstring, std::unordered_map<std::wstring, std::wstring>>{
		{L"Chinese", {
			{L"forward:main", L"TwinStar ToolKit - Forwarder"},
			{L"forward:launch", L"Launch"},
			{L"forward:js", L"JS"},
			{L"forward:js.execute", L"执行"},
			{L"forward:json", L"JSON"},
			{L"forward:json.format", L"格式化"},
			{L"forward:json.format.batch", L"[批处理] 格式化"},
			{L"forward:data", L"Data"},
			{L"forward:data.hash.md5", L"MD5 散列"},
			{L"forward:data.encoding.base64.encode", L"Base64 编码"},
			{L"forward:data.encoding.base64.decode", L"Base64 解码"},
			{L"forward:data.encryption.xor.encrypt", L"XOR 加密"},
			{L"forward:data.encryption.rijndael.encrypt", L"Rijndael 加密"},
			{L"forward:data.encryption.rijndael.decrypt", L"Rijndael 解密"},
			{L"forward:data.compression.deflate.compress", L"Deflate 压缩"},
			{L"forward:data.compression.deflate.uncompress", L"Deflate 解压"},
			{L"forward:data.compression.zlib.compress", L"ZLib 压缩"},
			{L"forward:data.compression.zlib.uncompress", L"ZLib 解压"},
			{L"forward:data.compression.gzip.compress", L"GZip 压缩"},
			{L"forward:data.compression.gzip.uncompress", L"GZip 解压"},
			{L"forward:data.compression.bzip2.compress", L"BZip2 压缩"},
			{L"forward:data.compression.bzip2.uncompress", L"BZip2 解压"},
			{L"forward:data.compression.lzma.compress", L"Lzma 压缩"},
			{L"forward:data.compression.lzma.uncompress", L"Lzma 解压"},
			{L"forward:data.differentiation.vcdiff.encode", L"VCDiff 编码"},
			{L"forward:data.differentiation.vcdiff.decode", L"VCDiff 解码"},
			{L"forward:image", L"Image"},
			{L"forward:image.transformation.flip", L"翻转"},
			{L"forward:image.transformation.scale", L"缩放"},
			{L"forward:image.transformation.scale_rate", L"比例缩放"},
			{L"forward:image.atlas.pack", L"图集打包"},
			{L"forward:image.atlas.unpack", L"图集解包"},
			{L"forward:image.atlas.pack_automatic", L"图集自动打包"},
			{L"forward:wwise.media", L"Wwise Media"},
			{L"forward:wwise.media.decode", L"解码"},
			{L"forward:wwise.media.decode.batch", L"[批处理] 解码"},
			{L"forward:wwise.sound_bank", L"Wwise Sound-Bank"},
			{L"forward:wwise.sound_bank.encode", L"编码"},
			{L"forward:wwise.sound_bank.decode", L"解码"},
			{L"forward:wwise.sound_bank.encode.batch", L"[批处理] 编码"},
			{L"forward:wwise.sound_bank.decode.batch", L"[批处理] 解码"},
			{L"forward:marmalade.dzip", L"Marmalade DZip"},
			{L"forward:marmalade.dzip.pack", L"打包"},
			{L"forward:marmalade.dzip.unpack", L"解包"},
			{L"forward:marmalade.dzip.pack_automatic", L"自动打包"},
			{L"forward:popcap.zlib", L"PopCap ZLib"},
			{L"forward:popcap.zlib.compress", L"压缩"},
			{L"forward:popcap.zlib.uncompress", L"解压"},
			{L"forward:popcap.zlib.compress.batch", L"[批处理] 压缩"},
			{L"forward:popcap.zlib.uncompress.batch", L"[批处理] 解压"},
			{L"forward:popcap.crypt_data", L"PopCap Crypt-Data"},
			{L"forward:popcap.crypt_data.encrypt", L"加密"},
			{L"forward:popcap.crypt_data.decrypt", L"解密"},
			{L"forward:popcap.crypt_data.encrypt.batch", L"[批处理] 加密"},
			{L"forward:popcap.crypt_data.decrypt.batch", L"[批处理] 解密"},
			{L"forward:popcap.reflection_object_notation", L"PopCap Reflection-Object-Notation"},
			{L"forward:popcap.reflection_object_notation.encode", L"编码"},
			{L"forward:popcap.reflection_object_notation.decode", L"解码"},
			{L"forward:popcap.reflection_object_notation.encrypt", L"加密"},
			{L"forward:popcap.reflection_object_notation.decrypt", L"解密"},
			{L"forward:popcap.reflection_object_notation.encode_then_encrypt", L"编码并加密"},
			{L"forward:popcap.reflection_object_notation.decrypt_then_decode", L"解密并解码"},
			{L"forward:popcap.reflection_object_notation.decode_lenient", L"宽松解码"},
			{L"forward:popcap.reflection_object_notation.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.reflection_object_notation.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.reflection_object_notation.encrypt.batch", L"[批处理] 加密"},
			{L"forward:popcap.reflection_object_notation.decrypt.batch", L"[批处理] 解密"},
			{L"forward:popcap.reflection_object_notation.encode_then_encrypt.batch", L"[批处理] 编码并加密"},
			{L"forward:popcap.reflection_object_notation.decrypt_then_decode.batch", L"[批处理] 解密并解码"},
			{L"forward:popcap.texture", L"PopCap Texture"},
			{L"forward:popcap.texture.encode", L"编码"},
			{L"forward:popcap.texture.decode", L"解码"},
			{L"forward:popcap.texture.encode:rgba_8888_o", L"编码 ~ rgba_8888_o"},
			{L"forward:popcap.texture.decode:rgba_8888_o", L"解码 ~ rgba_8888_o"},
			{L"forward:popcap.texture.encode:argb_8888", L"编码 ~ argb_8888"},
			{L"forward:popcap.texture.decode:argb_8888", L"解码 ~ argb_8888"},
			{L"forward:popcap.texture.encode:rgba_pvrtc4", L"编码 ~ rgba_pvrtc4"},
			{L"forward:popcap.texture.decode:rgba_pvrtc4", L"解码 ~ rgba_pvrtc4"},
			{L"forward:popcap.texture.encode:rgb_etc1_a_8", L"编码 ~ rgb_etc1_a_8"},
			{L"forward:popcap.texture.decode:rgb_etc1_a_8", L"解码 ~ rgb_etc1_a_8"},
			{L"forward:popcap.texture.encode:rgb_etc1_a_palette", L"编码 ~ rgb_etc1_a_palette"},
			{L"forward:popcap.texture.decode:rgb_etc1_a_palette", L"解码 ~ rgb_etc1_a_palette"},
			{L"forward:popcap.u_texture", L"PopCap U-Texture"},
			{L"forward:popcap.u_texture.encode", L"编码"},
			{L"forward:popcap.u_texture.decode", L"解码"},
			{L"forward:popcap.u_texture.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.u_texture.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.sexy_texture", L"PopCap Sexy-Texture"},
			{L"forward:popcap.sexy_texture.encode", L"编码"},
			{L"forward:popcap.sexy_texture.decode", L"解码"},
			{L"forward:popcap.sexy_texture.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.sexy_texture.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.animation", L"PopCap Animation"},
			{L"forward:popcap.animation.encode", L"编码"},
			{L"forward:popcap.animation.decode", L"解码"},
			{L"forward:popcap.animation.convert.flash.from", L"Flash 转换自JSON"},
			{L"forward:popcap.animation.convert.flash.to", L"Flash 转换至JSON"},
			{L"forward:popcap.animation.convert.flash.resize", L"Flash 图像分辨率调整"},
			{L"forward:popcap.animation.convert.flash.resize:1536", L"Flash 图像分辨率调整 ~ 1536"},
			{L"forward:popcap.animation.convert.flash.link_media", L"Flash 创建图像文件链接"},
			{L"forward:popcap.animation.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.animation.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.animation.convert.flash.from.batch", L"[批处理] Flash 转换自JSON"},
			{L"forward:popcap.animation.convert.flash.to.batch", L"[批处理] Flash 转换至JSON"},
			{L"forward:popcap.animation.convert.flash.resize.batch", L"[批处理] Flash 图像分辨率调整"},
			{L"forward:popcap.animation.convert.flash.resize.batch:1536", L"[批处理] Flash 图像分辨率调整 ~ 1536"},
			{L"forward:popcap.animation.convert.flash.link_media.batch", L"[批处理] Flash 创建图像文件链接"},
			{L"forward:popcap.re_animation", L"PopCap Re-Animation"},
			{L"forward:popcap.re_animation.encode", L"编码"},
			{L"forward:popcap.re_animation.decode", L"解码"},
			{L"forward:popcap.re_animation.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.re_animation.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.particle", L"PopCap Particle"},
			{L"forward:popcap.particle.encode", L"编码"},
			{L"forward:popcap.particle.decode", L"解码"},
			{L"forward:popcap.particle.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.particle.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.trail", L"PopCap Trail"},
			{L"forward:popcap.trail.encode", L"编码"},
			{L"forward:popcap.trail.decode", L"解码"},
			{L"forward:popcap.trail.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.trail.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.effect", L"PopCap Effect"},
			{L"forward:popcap.effect.encode", L"编码"},
			{L"forward:popcap.effect.decode", L"解码"},
			{L"forward:popcap.effect.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.effect.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.character_font_widget_2", L"PopCap Character-Font-Widget-2"},
			{L"forward:popcap.character_font_widget_2.encode", L"编码"},
			{L"forward:popcap.character_font_widget_2.decode", L"解码"},
			{L"forward:popcap.character_font_widget_2.encode.batch", L"[批处理] 编码"},
			{L"forward:popcap.character_font_widget_2.decode.batch", L"[批处理] 解码"},
			{L"forward:popcap.package", L"PopCap Package"},
			{L"forward:popcap.package.pack", L"打包"},
			{L"forward:popcap.package.unpack", L"解包"},
			{L"forward:popcap.package.pack_automatic", L"自动打包"},
			{L"forward:popcap.package.encrypt", L"加密"},
			{L"forward:popcap.resource_stream_group", L"PopCap Resource-Stream-Group"},
			{L"forward:popcap.resource_stream_group.pack", L"打包"},
			{L"forward:popcap.resource_stream_group.unpack", L"解包"},
			{L"forward:popcap.resource_stream_bundle", L"PopCap Resource-Stream-Bundle"},
			{L"forward:popcap.resource_stream_bundle.pack", L"打包"},
			{L"forward:popcap.resource_stream_bundle.unpack", L"解包"},
			{L"forward:popcap.resource_stream_bundle.resource_convert", L"资源转换"},
			{L"forward:popcap.resource_stream_bundle.repair", L"修复"},
			{L"forward:popcap.resource_stream_bundle_patch", L"PopCap Resource-Stream-Bundle-Patch"},
			{L"forward:popcap.resource_stream_bundle_patch.encode", L"编码"},
			{L"forward:popcap.resource_stream_bundle_patch.decode", L"解码"},
			{L"forward:pvz2.text_table", L"PvZ-2 Text-Table"},
			{L"forward:pvz2.text_table.convert", L"转换"},
			{L"forward:pvz2.remote_android_helper", L"PvZ-2 Remote-Android-Helper"},
			{L"forward:pvz2.remote_android_helper.launch:pull_main_package", L"拉取主数据包"},
			{L"forward:pvz2.remote_android_helper.launch:push_main_package", L"推送主数据包"},
			{L"forward:pvz2.remote_android_helper.launch:pull_local_profile", L"拉取本地配置"},
			{L"forward:pvz2.remote_android_helper.launch:push_local_profile", L"推送本地配置"},
			{L"forward:pvz2.remote_android_helper.launch:pull_player_profile", L"拉取玩家配置"},
			{L"forward:pvz2.remote_android_helper.launch:push_player_profile", L"推送玩家配置"},
			{L"forward:pvz2.remote_android_helper.launch:pull_content_delivery", L"拉取内容分发"},
			{L"forward:pvz2.remote_android_helper.launch:push_content_delivery", L"推送内容分发"},
			{L"forward:pvz2.remote_android_helper.launch:clear_snapshot", L"清除快照"},
		}},
		{L"English", {
			{L"forward:main", L"TwinStar ToolKit - Extension"},
			{L"forward:launch", L"Launch"},
			{L"forward:js", L"JS"},
			{L"forward:js.execute", L"Execute"},
			{L"forward:json", L"JSON"},
			{L"forward:json.format", L"Format"},
			{L"forward:json.format.batch", L"[BATCH] Format"},
			{L"forward:data", L"Data"},
			{L"forward:data.hash.md5", L"MD5 Hash"},
			{L"forward:data.encoding.base64.encode", L"Base64 Encode"},
			{L"forward:data.encoding.base64.decode", L"Base64 Decode"},
			{L"forward:data.encryption.xor.encrypt", L"XOR Encrypt"},
			{L"forward:data.encryption.rijndael.encrypt", L"Rijndael Encrypt"},
			{L"forward:data.encryption.rijndael.decrypt", L"Rijndael Decrypt"},
			{L"forward:data.compression.deflate.compress", L"Deflate Compress"},
			{L"forward:data.compression.deflate.uncompress", L"Deflate Uncompress"},
			{L"forward:data.compression.zlib.compress", L"ZLib Compress"},
			{L"forward:data.compression.zlib.uncompress", L"ZLib Uncompress"},
			{L"forward:data.compression.gzip.compress", L"GZip Compress"},
			{L"forward:data.compression.gzip.uncompress", L"GZip Uncompress"},
			{L"forward:data.compression.bzip2.compress", L"BZip2 Compress"},
			{L"forward:data.compression.bzip2.uncompress", L"BZip2 Uncompress"},
			{L"forward:data.compression.lzma.compress", L"Lzma Compress"},
			{L"forward:data.compression.lzma.uncompress", L"Lzma Uncompress"},
			{L"forward:data.differentiation.vcdiff.encode", L"VCDiff Encode"},
			{L"forward:data.differentiation.vcdiff.decode", L"VCDiff Decode"},
			{L"forward:image", L"Image"},
			{L"forward:image.transformation.flip", L"Flip"},
			{L"forward:image.transformation.scale", L"Scale"},
			{L"forward:image.transformation.scale_rate", L"Scale by rate"},
			{L"forward:image.atlas.pack", L"Atlas Pack"},
			{L"forward:image.atlas.unpack", L"Atlas Unpack"},
			{L"forward:image.atlas.pack_automatic", L"Atlas Pack by automatic"},
			{L"forward:wwise.media", L"Wwise Media"},
			{L"forward:wwise.media.decode", L"Decode"},
			{L"forward:wwise.media.decode.batch", L"[BATCH] Decode"},
			{L"forward:wwise.sound_bank", L"Wwise Sound-Bank"},
			{L"forward:wwise.sound_bank.encode", L"Encode"},
			{L"forward:wwise.sound_bank.decode", L"Decode"},
			{L"forward:wwise.sound_bank.encode.batch", L"[BATCH] Encode"},
			{L"forward:wwise.sound_bank.decode.batch", L"[BATCH] Decode"},
			{L"forward:marmalade.dzip", L"Marmalade DZip"},
			{L"forward:marmalade.dzip.pack", L"Pack"},
			{L"forward:marmalade.dzip.unpack", L"Unpack"},
			{L"forward:marmalade.dzip.pack_automatic", L"Pack by automatic"},
			{L"forward:popcap.zlib", L"PopCap ZLib"},
			{L"forward:popcap.zlib.compress", L"Compress"},
			{L"forward:popcap.zlib.uncompress", L"Uncompress"},
			{L"forward:popcap.zlib.compress.batch", L"[BATCH] Compress"},
			{L"forward:popcap.zlib.uncompress.batch", L"[BATCH] Uncompress"},
			{L"forward:popcap.crypt_data", L"PopCap Crypt-Data"},
			{L"forward:popcap.crypt_data.encrypt", L"Encrypt"},
			{L"forward:popcap.crypt_data.decrypt", L"Decrypt"},
			{L"forward:popcap.crypt_data.encrypt.batch", L"[BATCH] Encrypt"},
			{L"forward:popcap.crypt_data.decrypt.batch", L"[BATCH] Decrypt"},
			{L"forward:popcap.reflection_object_notation", L"PopCap Reflection-Object-Notation"},
			{L"forward:popcap.reflection_object_notation.encode", L"Encode"},
			{L"forward:popcap.reflection_object_notation.decode", L"Decode"},
			{L"forward:popcap.reflection_object_notation.encrypt", L"Encrypt"},
			{L"forward:popcap.reflection_object_notation.decrypt", L"Decrypt"},
			{L"forward:popcap.reflection_object_notation.encode_then_encrypt", L"Encode && Encrypt"},
			{L"forward:popcap.reflection_object_notation.decrypt_then_decode", L"Decrypt && Decode"},
			{L"forward:popcap.reflection_object_notation.decode_lenient", L"Decode by lenient"},
			{L"forward:popcap.reflection_object_notation.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.reflection_object_notation.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.reflection_object_notation.encrypt.batch", L"[BATCH] Encrypt"},
			{L"forward:popcap.reflection_object_notation.decrypt.batch", L"[BATCH] Decrypt"},
			{L"forward:popcap.reflection_object_notation.encode_then_encrypt.batch", L"[BATCH] Encode && Encrypt"},
			{L"forward:popcap.reflection_object_notation.decrypt_then_decode.batch", L"[BATCH] Decrypt && Decode"},
			{L"forward:popcap.texture", L"PopCap Texture"},
			{L"forward:popcap.texture.encode", L"Encode"},
			{L"forward:popcap.texture.decode", L"Decode"},
			{L"forward:popcap.texture.encode:rgba_8888_o", L"Encode ~ rgba_8888_o"},
			{L"forward:popcap.texture.decode:rgba_8888_o", L"Decode ~ rgba_8888_o"},
			{L"forward:popcap.texture.encode:argb_8888", L"Encode ~ argb_8888"},
			{L"forward:popcap.texture.decode:argb_8888", L"Decode ~ argb_8888"},
			{L"forward:popcap.texture.encode:rgba_pvrtc4", L"Encode ~ rgba_pvrtc4"},
			{L"forward:popcap.texture.decode:rgba_pvrtc4", L"Decode ~ rgba_pvrtc4"},
			{L"forward:popcap.texture.encode:rgb_etc1_a_8", L"Encode ~ rgb_etc1_a_8"},
			{L"forward:popcap.texture.decode:rgb_etc1_a_8", L"Decode ~ rgb_etc1_a_8"},
			{L"forward:popcap.texture.encode:rgb_etc1_a_palette", L"Encode ~ rgb_etc1_a_palette"},
			{L"forward:popcap.texture.decode:rgb_etc1_a_palette", L"Decode ~ rgb_etc1_a_palette"},
			{L"forward:popcap.u_texture", L"PopCap U-Texture"},
			{L"forward:popcap.u_texture.encode", L"Encode"},
			{L"forward:popcap.u_texture.decode", L"Decode"},
			{L"forward:popcap.u_texture.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.u_texture.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.sexy_texture", L"PopCap Sexy-Texture"},
			{L"forward:popcap.sexy_texture.encode", L"Encode"},
			{L"forward:popcap.sexy_texture.decode", L"Decode"},
			{L"forward:popcap.sexy_texture.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.sexy_texture.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.animation", L"PopCap Animation"},
			{L"forward:popcap.animation.encode", L"Encode"},
			{L"forward:popcap.animation.decode", L"Decode"},
			{L"forward:popcap.animation.convert.flash.from", L"Flash Convert from JSON"},
			{L"forward:popcap.animation.convert.flash.to", L"Flash Convert to JSON"},
			{L"forward:popcap.animation.convert.flash.resize", L"Flash Resize image"},
			{L"forward:popcap.animation.convert.flash.resize:1536", L"Flash Resize image ~ 1536"},
			{L"forward:popcap.animation.convert.flash.link_media", L"Flash Create links for image files"},
			{L"forward:popcap.animation.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.animation.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.animation.convert.flash.from.batch", L"[BATCH] Flash Convert from JSON"},
			{L"forward:popcap.animation.convert.flash.to.batch", L"[BATCH] Flash Convert to JSON"},
			{L"forward:popcap.animation.convert.flash.resize.batch", L"[BATCH] Flash Resize image"},
			{L"forward:popcap.animation.convert.flash.resize.batch:1536", L"[BATCH] Flash Resize image ~ 1536"},
			{L"forward:popcap.animation.convert.flash.link_media.batch", L"[BATCH] Flash Create links for image files"},
			{L"forward:popcap.re_animation", L"PopCap Re-Animation"},
			{L"forward:popcap.re_animation.encode", L"Encode"},
			{L"forward:popcap.re_animation.decode", L"Decode"},
			{L"forward:popcap.re_animation.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.re_animation.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.particle", L"PopCap Particle"},
			{L"forward:popcap.particle.encode", L"Encode"},
			{L"forward:popcap.particle.decode", L"Decode"},
			{L"forward:popcap.particle.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.particle.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.trail", L"PopCap Trail"},
			{L"forward:popcap.trail.encode", L"Encode"},
			{L"forward:popcap.trail.decode", L"Decode"},
			{L"forward:popcap.trail.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.trail.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.effect", L"PopCap Effect"},
			{L"forward:popcap.effect.encode", L"Encode"},
			{L"forward:popcap.effect.decode", L"Decode"},
			{L"forward:popcap.effect.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.effect.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.character_font_widget_2", L"PopCap Character-Font-Widget-2"},
			{L"forward:popcap.character_font_widget_2.encode", L"Encode"},
			{L"forward:popcap.character_font_widget_2.decode", L"Decode"},
			{L"forward:popcap.character_font_widget_2.encode.batch", L"[BATCH] Encode"},
			{L"forward:popcap.character_font_widget_2.decode.batch", L"[BATCH] Decode"},
			{L"forward:popcap.package", L"PopCap Package"},
			{L"forward:popcap.package.pack", L"Pack"},
			{L"forward:popcap.package.unpack", L"Unpack"},
			{L"forward:popcap.package.pack_automatic", L"Pack by automatic"},
			{L"forward:popcap.package.encrypt", L"Encrypt"},
			{L"forward:popcap.resource_stream_group", L"PopCap Resource-Stream-Group"},
			{L"forward:popcap.resource_stream_group.pack", L"Pack"},
			{L"forward:popcap.resource_stream_group.unpack", L"Unpack"},
			{L"forward:popcap.resource_stream_bundle", L"PopCap Resource-Stream-Bundle"},
			{L"forward:popcap.resource_stream_bundle.pack", L"Pack"},
			{L"forward:popcap.resource_stream_bundle.unpack", L"Unpack"},
			{L"forward:popcap.resource_stream_bundle.resource_convert", L"Resource convert"},
			{L"forward:popcap.resource_stream_bundle.repair", L"Repair"},
			{L"forward:popcap.resource_stream_bundle_patch", L"PopCap Resource-Stream-Bundle-Patch"},
			{L"forward:popcap.resource_stream_bundle_patch.encode", L"Encode"},
			{L"forward:popcap.resource_stream_bundle_patch.decode", L"Decode"},
			{L"forward:pvz2.text_table", L"PvZ-2 Text-Table"},
			{L"forward:pvz2.text_table.convert", L"Convert"},
			{L"forward:pvz2.remote_android_helper", L"PvZ-2 Remote-Android-Helper"},
			{L"forward:pvz2.remote_android_helper.launch:pull_main_package", L"Pull main package"},
			{L"forward:pvz2.remote_android_helper.launch:push_main_package", L"Push main package"},
			{L"forward:pvz2.remote_android_helper.launch:pull_local_profile", L"Pull local profile"},
			{L"forward:pvz2.remote_android_helper.launch:push_local_profile", L"Push local profile"},
			{L"forward:pvz2.remote_android_helper.launch:pull_player_profile", L"Pull player profile"},
			{L"forward:pvz2.remote_android_helper.launch:push_player_profile", L"Push player profile"},
			{L"forward:pvz2.remote_android_helper.launch:pull_content_delivery", L"Pull content delivery"},
			{L"forward:pvz2.remote_android_helper.launch:push_content_delivery", L"Push content delivery"},
			{L"forward:pvz2.remote_android_helper.launch:clear_snapshot", L"Clear snapshot"},
		}},
	};

	#pragma endregion

	#pragma region utility

	inline auto query (
		std::wstring const & key
	) -> std::wstring const & {
		auto language = get_register_value_string(k_register_key_parent, k_register_key_path, L"language").value_or(L"Chinese");
		return g_table.at(language).at(key);
	}

	#pragma endregion

}