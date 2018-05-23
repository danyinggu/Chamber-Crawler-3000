cc3k : main.o textdisplay.o controller.o cell.o game.o player.o enemy.o shade.o vampire.o dwarf.o gold.o small.o dragonhoard.o merchanthoard.o normal.o item.o dragon.o human.o elf.o drow.o troll.o goblin.o orcs.o halfling.o merchant.o potion.o decorator.o ba.o bd.o wa.o wd.o
	g++ main.o textdisplay.o controller.o cell.o game.o player.o enemy.o shade.o vampire.o dwarf.o gold.o small.o dragonhoard.o merchanthoard.o normal.o item.o dragon.o human.o elf.o drow.o troll.o goblin.o orcs.o halfling.o merchant.o potion.o decorator.o ba.o bd.o wa.o wd.o -o cc3k
controller.o : controller.cc controller.h textdisplay.h player.h game.h
	g++ -c controller.cc
game.o : game.cc game.h cell.h player.h enemy.h gold.h
	g++ -c game.cc
cell.o : cell.cc cell.h player.h game.h enemy.h gold.h small.h normal.h merchanthoard.h dragonhoard.h
	g++ -c cell.cc
player.o : player.cc player.h
	g++ -c player.cc
enemy.o : enemy.cc enemy.h
	g++ -c enemy.cc
shade.o : shade.cc shade.h player.h
	g++ -c shade.cc
potion.o : potion.cc potion.h item.h
	g++ -c potion.cc
decorator.o : decorator.cc decorator.h player.h
	g++ -c decorator.cc
ba.o : ba.cc ba.h decorator.h
	g++ -c ba.cc
bd.o : bd.cc bd.h decorator.h
	g++ -c bd.cc
wa.o : wa.cc wa.h decorator.h
	g++ -c wa.cc
wd.o : wd.cc wd.h decorator.h
	g++ -c wd.cc
vampire.o : vampire.cc vampire.h player.h dwarf.h enemy.h
	g++ -c vampire.cc
dwarf.o : dwarf.cc dwarf.h enemy.h player.h vampire.h
	g++ -c dwarf.cc
textdisplay.o : textdisplay.cc textdisplay.h
	g++ -c textdisplay.cc
drow.o : drow.cc drow.h player.h
	g++ -c drow.cc
halfling.o : halfling.cc halfling.h enemy.h
	g++ -c halfling.cc
merchant.o : merchant.cc merchant.h enemy.h
	g++ -c merchant.cc
goblin.o : goblin.cc goblin.h player.h
	g++ -c goblin.cc
orcs.o : orcs.cc orcs.h enemy.h
	g++ -c orcs.cc
troll.o : troll.cc troll.h player.h
	g++ -c troll.cc
item.o : item.cc item.h decorator.h ba.h bd.h wa.h wd.h
	g++ -c item.cc
gold.o : gold.cc gold.h item.h
	g++ -c gold.cc
elf.o : elf.cc elf.h enemy.h
	g++ -c elf.cc
small.o : small.cc small.h gold.h
	g++ -c small.cc
normal.o : normal.cc normal.h gold.h
	g++ -c normal.cc
merchanthoard.o : merchanthoard.cc merchanthoard.h gold.h
	g++ -c merchanthoard.cc
dragonhoard.o : dragonhoard.cc dragonhoard.h gold.h
	g++ -c dragonhoard.cc
dragon.o : dragon.cc dragon.h enemy.h
	g++ -c dragon.cc
human.o : human.cc human.h normal.h
	g++ -c human.cc
main.o : textdisplay.h controller.h cell.h game.h player.h
	g++ -c main.cc
