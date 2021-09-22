# General
config.load_autoconfig()
c.auto_save.session = True
c.downloads.location.directory = '~/media/downloads'
c.content.default_encoding = "utf-8"
c.content.javascript.can_access_clipboard = True
c.editor.command = ["alacritty", "nvim", "-e", "exec {line}g{column0}l", "{file}"]
c.downloads.location.prompt = False
c.tabs.background = True
c.tabs.last_close = "close"
c.tabs.mousewheel_switching = False
c.spellcheck.languages = ["en-US"]

# URLs
c.url.searchengines = {
    "DEFAULT": "https://duckduckgo.com/?q={}",
    "DDG": "https://duckduckgo.com/?q={}",
    "Searx": "https://searx.fmac.xyz/?q={}",
}

# Privacy
c.content.geolocation = False
c.content.webrtc_ip_handling_policy = "default-public-interface-only"
c.content.autoplay = False
c.content.user_stylesheets = "~/.config/qutebrowser/discord.css"

c.colors.webpage.preferred_color_scheme = "light"
c.statusbar.widgets = ["progress", "keypress", "url", "history"]
c.tabs.position = "top"
c.tabs.width = "15%"
c.tabs.title.format = "{index}: {audio}{current_title}"
c.tabs.title.format_pinned = "{index}: {audio}{current_title}"
c.content.fullscreen.window = True
c.completion.shrink = True
c.completion.use_best_match = True

# Fonts
c.fonts.default_family = ["curie"]
c.fonts.completion.entry = "10pt curie"
c.fonts.prompts = "curie"
c.fonts.web.family.standard = "curie"
# c.fonts.web.family.fixed = "curie"
# c.fonts.web.family.serif = "curie"
# c.fonts.web.family.sans_serif = "curie"
# c.fonts.web.family.cursive = "curie"
# c.fonts.web.family.fantasy = "curie"

# Keys
bindings = {
    "m": "hint links spawn mpv {hint-url}",
    "<Ctrl-Shift-J>": "tab-move +",
    "<Ctrl-Shift-K>": "tab-move -",
    "co": "nop",
    "<Shift-Escape>": "fake-key <Escape>",
    "o": "set-cmd-text -s :open -s",
    "op": "set-cmd-text -s :open -s -p",
    "O": "set-cmd-text -s :open -t -s",
}

for key, bind in bindings.items():
    config.bind(key, bind)

# Blossom
bg = "#ede6e3"
completion = "#e6dad6"
soft = "#dad3d0"
hard = "#e3d0cb"

fg = "#6c605a"
light = "#938680"
lightpink = "#8f8678"
dark = "#574b45"

red = "#ce9c85"
# yellow = "#fbf1be"

# set qutebrowser colors

# Text color of the completion widget. May be a single color to use for
# all columns or a list of three colors, one for each column.
c.colors.completion.fg = fg

# Background color of the completion widget for odd rows.
c.colors.completion.odd.bg = completion

# Background color of the completion widget for even rows.
c.colors.completion.even.bg = completion

# Foreground color of completion widget category headers.
c.colors.completion.category.fg = bg

# Background color of the completion widget category headers.
c.colors.completion.category.bg = light

# Top border color of the completion widget category headers.
c.colors.completion.category.border.top = light

# Bottom border color of the completion widget category headers.
c.colors.completion.category.border.bottom = light

# Foreground color of the selected completion item.
c.colors.completion.item.selected.fg = fg

# Background color of the selected completion item.
c.colors.completion.item.selected.bg = red

# Top border color of the selected completion item.
c.colors.completion.item.selected.border.top = red

# Bottom border color of the selected completion item.
c.colors.completion.item.selected.border.bottom = red

# Foreground color of the matched text in the selected completion item.
c.colors.completion.item.selected.match.fg = dark

# Foreground color of the matched text in the completion.
c.colors.completion.match.fg = red

# Color of the scrollbar handle in the completion view.
c.colors.completion.scrollbar.fg = fg

# Color of the scrollbar in the completion view.
c.colors.completion.scrollbar.bg = bg

# Background color of disabled items in the context menu.
c.colors.contextmenu.disabled.bg = soft

# Foreground color of disabled items in the context menu.
c.colors.contextmenu.disabled.fg = dark

# Background color of the context menu. If set to null, the Qt default is used.
c.colors.contextmenu.menu.bg = bg

# Foreground color of the context menu. If set to null, the Qt default is used.
c.colors.contextmenu.menu.fg =  fg

# Background color of the context menu’s selected item. If set to null, the Qt default is used.
c.colors.contextmenu.selected.bg = soft

#Foreground color of the context menu’s selected item. If set to null, the Qt default is used.
c.colors.contextmenu.selected.fg = fg

# Background color for the download bar.
c.colors.downloads.bar.bg = bg

# Color gradient start for download text.
c.colors.downloads.start.fg = bg

# Color gradient start for download backgrounds.
c.colors.downloads.start.bg = red

# Color gradient end for download text.
c.colors.downloads.stop.fg = bg

# Color gradient stop for download backgrounds.
c.colors.downloads.stop.bg = red

# Foreground color for downloads with errors.
c.colors.downloads.error.fg = red

# Font color for hints.
c.colors.hints.fg = bg

# Background color for hints. Note that you can use a `rgba(...)` value
# for transparency.
c.colors.hints.bg = red

# Font color for the matched part of hints.
c.colors.hints.match.fg = fg

# Text color for the keyhint widget.
c.colors.keyhint.fg = fg

# Highlight color for keys to complete the current keychain.
c.colors.keyhint.suffix.fg = fg

# Background color of the keyhint widget.
c.colors.keyhint.bg = bg

# Foreground color of an error message.
c.colors.messages.error.fg = bg

# Background color of an error message.
c.colors.messages.error.bg = red

# Border color of an error message.
c.colors.messages.error.border = red

# Foreground color of a warning message.
c.colors.messages.warning.fg = bg

# Background color of a warning message.
c.colors.messages.warning.bg = lightpink

# Border color of a warning message.
c.colors.messages.warning.border = lightpink

# Foreground color of an info message.
c.colors.messages.info.fg = fg

# Background color of an info message.
c.colors.messages.info.bg = bg

# Border color of an info message.
c.colors.messages.info.border = bg

# Foreground color for prompts.
c.colors.prompts.fg = fg

# Border used around UI elements in prompts.
c.colors.prompts.border = bg

# Background color for prompts.
c.colors.prompts.bg = bg

# Background color for the selected item in filename prompts.
c.colors.prompts.selected.bg = soft

# Foreground color for the selected item in filename prompts.
c.colors.prompts.selected.fg = fg

# Foreground color of the statusbar.
c.colors.statusbar.normal.fg = red

# Background color of the statusbar.
c.colors.statusbar.normal.bg = bg

# Foreground color of the statusbar in insert mode.
c.colors.statusbar.insert.fg = bg

# Background color of the statusbar in insert mode.
c.colors.statusbar.insert.bg = red

# Foreground color of the statusbar in passthrough mode.
c.colors.statusbar.passthrough.fg = bg

# Background color of the statusbar in passthrough mode.
c.colors.statusbar.passthrough.bg = red

# Foreground color of the statusbar in private browsing mode.
c.colors.statusbar.private.fg = bg

# Background color of the statusbar in private browsing mode.
c.colors.statusbar.private.bg = soft

# Foreground color of the statusbar in command mode.
c.colors.statusbar.command.fg = fg

# Background color of the statusbar in command mode.
c.colors.statusbar.command.bg = bg

# Foreground color of the statusbar in private browsing + command mode.
c.colors.statusbar.command.private.fg = fg

# Background color of the statusbar in private browsing + command mode.
c.colors.statusbar.command.private.bg = bg

# Foreground color of the statusbar in caret mode.
c.colors.statusbar.caret.fg = bg

# Background color of the statusbar in caret mode.
c.colors.statusbar.caret.bg = lightpink

# Foreground color of the statusbar in caret mode with a selection.
c.colors.statusbar.caret.selection.fg = bg

# Background color of the statusbar in caret mode with a selection.
c.colors.statusbar.caret.selection.bg = red

# Background color of the progress bar.
c.colors.statusbar.progress.bg = red

# Default foreground color of the URL in the statusbar.
c.colors.statusbar.url.fg = fg

# Foreground color of the URL in the statusbar on error.
c.colors.statusbar.url.error.fg = red

# Foreground color of the URL in the statusbar for hovered links.
c.colors.statusbar.url.hover.fg = fg

# Foreground color of the URL in the statusbar on successful load
# (http).
c.colors.statusbar.url.success.http.fg = red

# Foreground color of the URL in the statusbar on successful load
# (https).
c.colors.statusbar.url.success.https.fg = red

# Foreground color of the URL in the statusbar when there's a warning.
c.colors.statusbar.url.warn.fg = lightpink

# Background color of the tab bar.
c.colors.tabs.bar.bg = bg

# Color gradient start for the tab indicator.
c.colors.tabs.indicator.start = red

# Color gradient end for the tab indicator.
c.colors.tabs.indicator.stop = red

# Color for the tab indicator on errors.
c.colors.tabs.indicator.error = red

# Foreground color of unselected odd tabs.
c.colors.tabs.odd.fg = fg

# Background color of unselected odd tabs.
c.colors.tabs.odd.bg = soft

# Foreground color of unselected even tabs.
c.colors.tabs.even.fg = fg

# Background color of unselected even tabs.
c.colors.tabs.even.bg = soft

# Background color of pinned unselected even tabs.
c.colors.tabs.pinned.even.bg = hard

# Foreground color of pinned unselected even tabs.
c.colors.tabs.pinned.even.fg = fg

# Background color of pinned unselected odd tabs.
c.colors.tabs.pinned.odd.bg = hard

# Foreground color of pinned unselected odd tabs.
c.colors.tabs.pinned.odd.fg = fg

# Background color of pinned selected even tabs.
c.colors.tabs.pinned.selected.even.bg = red

# Foreground color of pinned selected even tabs.
c.colors.tabs.pinned.selected.even.fg = fg

# Background color of pinned selected odd tabs.
c.colors.tabs.pinned.selected.odd.bg = red

# Foreground color of pinned selected odd tabs.
c.colors.tabs.pinned.selected.odd.fg = fg

# Foreground color of selected odd tabs.
c.colors.tabs.selected.odd.fg = fg

# Background color of selected odd tabs.
c.colors.tabs.selected.odd.bg = red

# Foreground color of selected even tabs.
c.colors.tabs.selected.even.fg = fg

# Background color of selected even tabs.
c.colors.tabs.selected.even.bg = red

# Background color for webpages if unset (or empty to use the theme's
# color).
c.colors.webpage.bg = bg
