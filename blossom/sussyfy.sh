#!/bin/sh

#variables
cr="\033[1;31m"
cg="\033[1;32m"
cb="\033[1;34m"

printf "${cg}[*] Your shit is gonna get purged.\n"
printf "${cr}"
read -p "[*] You sure? [Y/N] " allowed

case $allowed in
	Y*|y*)
		printf "${cb} [*] Copying configs...\n"
		cp -r config/* ~/.config
		printf "${cg} [*] Configs copied.\n"
		printf "${cb} [*] Copying local...\n"
		cp -r fonts/* ~/.local
		printf "${cg} [*] Local copied\n"
		printf "${cb} [*] Copying usr...\n"
		sudo cp -r usr/* /usr
		printf "${cg} [*] Copied etc.\n"
		printf "${cb} [*] Copying etc...\n"
		sudo cp -r etc/* /etc
		printf "${cg} [*] Copied etc.\n"
		printf "${cg}[*] Dotfiles Installed!\n";;
		*) printf "${cr}[-] Aborting!\n";;
esac
