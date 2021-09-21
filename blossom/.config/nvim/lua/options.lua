require('util').set_options {
	foldmethod = 'marker',
	shortmess = vim.o.shortmess .. 'I',
	completeopt = 'menuone,noinsert,noselect',

	-- Search options
	ignorecase = true,
	smartcase = true,
	incsearch = true,

	-- Saner split defaults
	splitright = true,
	splitbelow = true,

	-- System clipboard
	clipboard = 'unnamedplus',

  	-- Don't annoy me to save stuff on buffer switch
	hidden = true,

	-- Mouse support
	mouse = 'a',

	-- Numbers
	relativenumber = true,

	-- Tabitha
	tabstop = 4,
	shiftwidth = 4,
	autoindent = true,
	smartindent = true,

	-- Statuslines
	laststatus = 1,
	showtabline = 1,

	-- Aesthetics
	termguicolors = true,
	showmode = false,
	fcs = 'eob: ',

}

-- Forgive me, Lua 。゜゜(´Ｏ`) ゜゜。
-- Mountain
vim.cmd [[colorscheme blossom]]

vim.cmd([[autocmd VimLeave *.tex !texclear %]])

local g = vim.g

-- Disable Default Vim Plugins
g.loaded_gzip = 0
g.loaded_tar = 0
g.loaded_tarPlugin = 0
g.loaded_zipPlugin = 0
g.loaded_2html_plugin = 0
g.loaded_netrw = 0
g.loaded_netrwPlugin = 0
g.loaded_spec = 0
g.loaded_syncolor = 0

