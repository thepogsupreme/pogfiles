local present, tree_c = pcall(require, "nvim-tree.config")
if not present then
	return
end

local tree_cb = tree_c.nvim_tree_callback
local g = vim.g

vim.o.termguicolors = true


g.nvim_tree_icons = {
	default = " ",
	symlink = " ",

	git = {
		deleted = "",
    	ignored = "",
		renamed = "",
		staged = "✓",
		unmerged = "",
		unstaged = "✗ ",
		untracked = " ",
   },
}
