local install_path = vim.fn.stdpath('data')..'/site/pack/packer/opt/packer.nvim'

local execute = vim.api.nvim_command
local fn = vim.fn
if fn.empty(vim.fn.glob(install_path)) > 0 then
vim.fn.system({'git', 'clone', 'https://github.com/wbthomason/packer.nvim', install_path})
execute 'packadd packer.nvim'
end

vim.cmd [[packadd packer.nvim]]

require('packer').startup(function()

	-- Let packer maintain itself
	use {
		'wbthomason/packer.nvim', 
		opt = true
	}

	use {
		'tweekmonster/startuptime.vim', 
		cmd = 'StartupTime'
	}

	-- Quality of life
	use {
		'terrortylor/nvim-comment',
		cmd = 'CommentToggle',
		config = function()
			require('plugins.others').comment()
		end
	}

	use {
		'kyazdani42/nvim-tree.lua',
		cmd = "NvimTreeToggle"
	}
	
	use {'karb94/neoscroll.nvim'}

	-- Theme
	use 'thepogsupreme/mountain.nvim'

	use {
		'norcalli/nvim-colorizer.lua',
		event = 'BufRead',
		config = function()
			require('plugins.others').colorizer()
		end
	}

	-- Language Server:
	use {
		"nvim-treesitter/nvim-treesitter",
			event = "BufRead",
			config = function()
				require'plugins.treesitter'
			end
	}
	use {
		"kabouzeid/nvim-lspinstall",
		event = "BufRead"
	}

	use {
		"neovim/nvim-lspconfig",
		after = "nvim-lspinstall"
    }

	use {
        "hrsh7th/nvim-compe",
		event = "InsertEnter",
		config = function()
			require "plugins.compe"
		end,
		wants = "LuaSnip",
		requires = {
                {
					"L3MON4D3/LuaSnip",
					wants = "friendly-snippets",
					event = "InsertCharPre",
					config = function()
						require "plugins.luasnip"
					end
				},
				{
					"rafamadriz/friendly-snippets",
					event = "InsertCharPre"
				}
		}
	}

	-- Writing
	use {
		"Pocco81/TrueZen.nvim",
		cmd = {"TZAtaraxis", "TZMinimalist", "TZFocus"}
	}

	use {
		'folke/twilight.nvim',
		cmd = {'Twilight', 'TwilightEnable', 'TwilightDisable'}
	}

	-- Fuzzy finding
	use {
		"nvim-lua/plenary.nvim",
		event = "BufRead"
	}

	use {
		"nvim-lua/popup.nvim",
		after = "plenary.nvim"
	}

	use {
		"nvim-telescope/telescope.nvim",
		cmd = "Telescope",
	}

	-- Nvim config
	use 'svermeulen/vimpeccable'


	use {
		"lukas-reineke/indent-blankline.nvim",
		event = "BufRead",
	}

end)
