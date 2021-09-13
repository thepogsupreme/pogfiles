local vimp = require 'vimp'

vim.g.mapleader = ' '

vimp.nnoremap('J', 'mzJ`z')
vimp.nnoremap('zx', 'ZZ')

-- D = d$ and C = c$ ... but Y = yy !?
vimp.nnoremap('Y', 'y$')

-- Convenience functions
vimp.nnoremap('<leader>w', [[:up<cr>]])
vimp.nnoremap('<leader>r', [[:source $XDG_CONFIG_HOME/nvim/init.lua<cr>]])
vimp.nnoremap('<leader>n', [[:NvimTreeToggle<cr>]])
vimp.cnoremap('w!!', [[execute 'silent! write !sudo tee % >/dev/null' <bar> edit!<cr>]])

-- Zen
vimp.nnoremap('<leader>z', [[<:TZAtaraxis<CR>]])

-- Usable wraping
vimp.nnoremap('j', 'gj')
vimp.nnoremap('k', 'gk')

-- PDFs
vimp.nnoremap('<leader>c', [[:! compiler %<cr>]])
vimp.nnoremap('<leader>o', [[:! opout %<cr>]])

-- Some convenient brace expanding commands
vimp.inoremap(';b', '{<cr>}<esc>O')
vimp.inoremap(';;b', '{<cr>};<esc>O')
vimp.inoremap(';,b', '{<cr>};<esc>O')

-- Control backspace is pretty good
vimp.bind('ic', '', '<c-w>')

-- Easy to reach seperated system clipboard
for _, i in ipairs { 'y', 'd', 'p', 'P' } do
	vimp.rbind('nv', '<leader>' .. i, '+' .. i)
end

-- Default bindings for window manipulation are pretty bad ngl
for _, i in ipairs { 'h', 'j', 'k', 'l' } do
	vimp.nnoremap('<leader>' .. i, '<c-w>' .. i)
	local up = string.upper(i)
	vimp.nnoremap('<leader>' .. up, '<c-w>' .. up)
end

-- Telescope:
-- Files
vimp.nnoremap('<leader>f', [[:Telescope find_files<cr>]])

-- Grep
vimp.nnoremap('<leader>g', [[:Telescope live_grep<cr>]])

-- Commentor:
vimp.nnoremap('<leader>/', [[:CommentToggle<cr>]])
vimp.vnoremap('<leader>/', [[:CommentToggle<cr>]])
