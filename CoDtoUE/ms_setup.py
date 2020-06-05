import unreal_engine as ue

# Initialize our main modules.
ue.exec("ms_Init.py")

project_path = f"{os.path.dirname(sys.argv[0])}"
current_path = f"{project_path}/Plugins/CoDtoUE"

def init_megascans_ui():
    ue.exec("UI.py")

# Initialize our asyncio task. This task will be running in the background to check for new assets to import.
# loop = asyncio.new_event_loop()
# asyncio.set_event_loop(loop)
# ticker = ue.add_ticker(ms_ticker_loop)
# asyncio.ensure_future(ms_simple_timer(1))
print("Megascans Integration - LiveLink Initialized...")

# The following snippet is used to create the "Megascans" icon in the UE4 toolbar.

style = FSlateStyleSet('PyStyle')
brush = SlateBrush(TintColor=SlateColor(SpecifiedColor=FLinearColor(1, 0, 0, 1)))
style.set('SolidBrush001', brush)
brush2 = SlateBrush(ResourceName=(current_path + '/ToolLogo.png'), ImageSize=Vector2D(X=45, Y=45))
style.set('ImageBrush001', brush2)
style.register()


def fill_toolbar(toolbar):
    icon2 = FSlateIcon('PyStyle', 'ImageBrush001')
    toolbar.add_tool_bar_button('CoDtoUE', 'CoDtoUE', 'Open CoDtoUE', icon2, lambda: init_megascans_ui())


ue.add_tool_bar_extension('SimpleToolBarExtension', fill_toolbar)
