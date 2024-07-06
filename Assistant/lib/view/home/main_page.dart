import '/common.dart';
import '/module.dart';
import '/setting.dart';
import '/utility/convert_helper.dart';
import '/utility/control_helper.dart';
import '/utility/system_overlay_helper.dart';
import '/view/home/common.dart';
import '/view/home/blank_panel.dart';
import '/view/home/launcher_panel.dart';
import '/view/home/setting_panel.dart';
import '/view/home/about_panel.dart';
import 'dart:math';
import 'package:collection/collection.dart';
import 'package:provider/provider.dart';
import 'package:flutter/material.dart';

// ----------------

class MainPage extends StatefulWidget {

  const MainPage({
    super.key,
  });

  // ----------------

  // ----------------

  @override
  createState() => _MainPageState();

}

class _MainPageState extends State<MainPage> {

  late Widget                             _blankPanel;
  late List<(String, ModuleType, Widget)> _tabList;
  late Integer                            _tabIndex;

  Future<Void> _insertTabItem(
    ModuleLauncherConfiguration configuration,
  ) async {
    while (Navigator.canPop(context)) {
      Navigator.pop(context);
    }
    this._tabList.add((configuration.title, configuration.type, ModuleHelper.query(configuration.type).mainPage(configuration.option)));
    this._tabIndex = this._tabList.length - 1;
    this.setState(() {});
    await Future.delayed(const Duration(milliseconds: 10));
    return;
  }

  Future<Void> _removeTabItem(
    Integer index,
  ) async {
    var itemState = this._tabList[index].$3.key!.as<GlobalKey>().currentState!.as<CustomModulePageState>();
    if (!await itemState.modulePageRequestClose()) {
      return;
    }
    this._tabList.removeAt(index);
    if (this._tabIndex > index) {
      this._tabIndex--;
    }
    this._tabIndex = min(this._tabIndex, this._tabList.length - 1);
    this.setState(() {});
    return;
  }

  Future<Void> _toggleTabItem(
    Integer index,
  ) async {
    assertTest(0 <= index && index < this._tabList.length);
    this._tabIndex = index;
    this.setState(() {});
    return;
  }

  Future<Void> _showCommanderPanel(
  ) async {
    var command = <String>[];
    var confirmed = await ControlHelper.showCustomModalDialog<Boolean>(context, CustomModalDialog(
      title: 'Commander',
      contentBuilder: (context, setState) => [
        CustomTextFieldWithFocus(
          keyboardType: TextInputType.multiline,
          inputFormatters: const [],
          decoration: const InputDecoration(
            contentPadding: EdgeInsets.fromLTRB(12, 16, 12, 16),
            filled: false,
            border: OutlineInputBorder(),
          ),
          value: ConvertHelper.makeStringListToStringWithLine(command),
          onChanged: (value) async {
            command = ConvertHelper.parseStringListFromStringWithLine(value);
            setState(() {});
          },
        ),
      ],
      actionBuilder: (context) => [
        TextButton(
          onPressed: () => Navigator.pop(context, false),
          child: const Text('Cancel'),
        ),
        TextButton(
          onPressed: () => Navigator.pop(context, true),
          child: const Text('Handle'),
        ),
      ],
    )) ?? false;
    if (confirmed) {
      await Provider.of<SettingProvider>(context, listen: false).state.mHandleCommand!(command);
    }
    return;
  }

  Future<Void> _showLauncherPanel(
  ) async {
    await ControlHelper.showCustomModalBottomSheet<Void>(this.context, CustomModalBottomSheet(
      title: 'Launcher',
      contentBuilder: (context, setState) => [
        LauncherPanel(
          onLaunch: (configuration) async {
            Navigator.pop(context);
            await this._insertTabItem(configuration);
          },
        ),
      ],
    ));
    return;
  }

  // ----------------

  @override
  initState() {
    super.initState();
    this._blankPanel = BlankPanel(
      showLauncherPanel: this._showLauncherPanel,
    );
    this._tabList = [];
    this._tabIndex = -1;
    {
      var setting = Provider.of<SettingProvider>(this.context, listen: false);
      setting.state.mHomeShowCommanderPanel = this._showCommanderPanel;
      setting.state.mHomeShowLauncherPanel = this._showLauncherPanel;
      setting.state.mHomeInsertTabItem = this._insertTabItem;
    }
    return;
  }

  @override
  didUpdateWidget(oldWidget) {
    super.didUpdateWidget(oldWidget);
    return;
  }

  @override
  dispose() {
    super.dispose();
    return;
  }

  @override
  build(context) {
    SystemOverlayHelper.apply(Theme.of(context).colorScheme.brightness);
    return Scaffold(
      appBar: AppBar(
        systemOverlayStyle: SystemOverlayHelper.query(Theme.of(context).colorScheme.brightness),
        centerTitle: false,
        elevation: 3,
        scrolledUnderElevation: 3,
        backgroundColor: Colors.transparent,
        title: const SizedBox(),
        leading: const SizedBox(),
        actions: [
          Expanded(
            child: CustomTitleBar(
              title: this._tabList.isEmpty ? '' : this._tabList[this._tabIndex].$1,
              leading: Builder(
                builder: (context) => IconButton(
                  tooltip: 'Navigation',
                  icon: const Icon(IconSymbols.menu),
                  onPressed: () async {
                    Scaffold.of(context).openDrawer();
                  },
                ),
              ),
            ),
          ),
        ],
      ),
      drawer: NavigationDrawer(
        children: [
          const SizedBox(height: 16),
          const CustomNavigationDrawerLabel(
            label: 'Assistant',
          ),
          CustomNavigationDrawerItem(
            selected: false,
            icon: IconSymbols.keyboard_command_key,
            label: 'Commander',
            action: const [],
            onPressed: () async {
              Navigator.pop(context);
              await this._showCommanderPanel();
            },
          ),
          CustomNavigationDrawerItem(
            selected: false,
            icon: IconSymbols.widgets,
            label: 'Launcher',
            action: const [],
            onPressed: () async {
              Navigator.pop(context);
              await this._showLauncherPanel();
            },
          ),
          const CustomNavigationDrawerDivider(),
          if (this._tabList.isEmpty)
            const SizedBox(height: 16),
          ...this._tabList.mapIndexed((index, value) => CustomNavigationDrawerItem(
            key: ObjectKey(value), // NOTE : fix button ripple effect error when remove item
            selected: index == this._tabIndex,
            icon: ModuleHelper.query(value.$2).icon,
            label: value.$1,
            action: [
              IconButton(
                tooltip: 'Remove',
                icon: const Icon(IconSymbols.remove),
                onPressed: () async {
                  await this._removeTabItem(index);
                },
              ),
            ],
            onPressed: () async {
              Navigator.pop(context);
              await this._toggleTabItem(index);
            },
          )),
          const CustomNavigationDrawerDivider(),
          CustomNavigationDrawerItem(
            selected: false,
            icon: IconSymbols.settings,
            label: 'Setting',
            action: const [],
            onPressed: () async {
              Navigator.pop(context);
              await ControlHelper.showCustomModalBottomSheet<Void>(context, CustomModalBottomSheet(
                title: 'Setting',
                contentBuilder: (context, setState) => [
                  const SettingPanel(),
                ],
              ));
            },
          ),
          CustomNavigationDrawerItem(
            selected: false,
            icon: IconSymbols.contact_support,
            label: 'About',
            action: const [],
            onPressed: () async {
              Navigator.pop(context);
              await ControlHelper.showCustomModalBottomSheet<Void>(context, CustomModalBottomSheet(
                title: 'About',
                contentBuilder: (context, setState) => [
                  const AboutPanel(),
                ],
              ));
            },
          ),
          const SizedBox(height: 16),
        ],
      ),
      body: Stack(
        children: [
          Offstage(
            offstage: this._tabIndex != -1,
            child: this._blankPanel,
          ),
          ...this._tabList.mapIndexed((index, value) => Offstage(
            offstage: this._tabIndex != index,
            child: value.$3,
          )),
        ],
      ),
    );
  }

}
