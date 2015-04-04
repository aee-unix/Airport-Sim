#!/bin/bash
# Help Vim format C++ code much more better.

mkdir -p $HOME/.vim/bundle
git clone https://github.com/gmarik/Vundle.vim.git $HOME/.vim/bundle/Vundle.vim

if [ -f $HOME/.vimrc ]; then
	echo "Do you want to keep the old contents of your previous .vimrc? [y/n]"
	read response
	case $response
		y)
			cat vimrc >> $HOME/.vimrc
			;;
		*)
			mv vimrc $HOME/.vimrc
	esac
else
	mv vimrc $HOME/.vimrc
fi

vim -c PluginInstall

echo "Vim should now be set up to conform to a group standard."
