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

# UI
import mountain.draw
mountain.draw.konda(c, {
    'spacing': {
        'vertical': 6,
        'horizontal': 8
    }
})

c.colors.webpage.preferred_color_scheme = "dark"
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
# c.fonts.web.family.standard = "curie"
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
