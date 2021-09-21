require 'options'

local async
async =
	vim.loop.new_async(
	vim.schedule_wrap(
		function()
			require 'plugins'
			require 'keybinds'

			async:close()
		end
    )
)
async:send()
