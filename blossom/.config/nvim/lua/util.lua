local M = {}

function M.set_vars(tbl)
  for var, value in pairs(tbl) do
    vim.g[var] = value
  end
end

function M.set_options(tbl)
  for var, value in pairs(tbl) do
    vim.opt[var] = value
  end
end

-- Nabbed from https://github.com/L3MON4D3/Luasnip/issues/1#issuecomment-835241958
function M.prequire(...)
	local status, lib = pcall(require, ...)
		if status then
			return lib
		end
		return nil
	end

return M
