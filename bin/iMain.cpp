#include "iGraphics.h"





int 25 =25;
int mazeWidth1=25;
int startx=5;
int starty=520;
int map1CoordinateX[21][19];
int map1CoordinateY[21][19];
int map2CoordinateX[21][19];
int map2CoordinateY[21][19];
int map3CoordinateX[17][36];
int map3CoordinateY[17][36];
int map4CoordinateX[19][40];
int map4CoordinateY[19][40];

int menuc=0;
int playgamec=0;
int difficultyc=0;
int highscorec=0;
int mazeselectorc=2;
int settingsc=0;
int creditsc=0;
int rulesc=0;
int quitc=0;
int selected;
int levelintro=0;
int pausec=0;
int backgroundselectorc=0;
int bgimage=0;

int maze=0;
int intro=0;
int exitintroimage=0;
int ratul=0;
char playerName[100] = "";
char namestr[100];
int nameIndex = 0;
bool typingName = false;


bool soundOn=true;
bool startintro=true;
bool exitintro ;
bool mainmenu;
bool difficulty;
bool playgameintro;
bool highscore;
bool settings;
bool credits;
bool rules;
bool quit;
bool mazeselector;
bool playingstart;
bool levelselect;
bool pause ;
bool backgroundselector;

char introimage[142][50]={"introimage/introimage (1).jpg", "introimage/introimage (2).jpg", "introimage/introimage (3).jpg", "introimage/introimage (4).jpg", "introimage/introimage (5).jpg", "introimage/introimage (6).jpg", "introimage/introimage (7).jpg", "introimage/introimage (8).jpg", "introimage/introimage (9).jpg", "introimage/introimage (10).jpg", "introimage/introimage (11).jpg", "introimage/introimage (12).jpg", "introimage/introimage (13).jpg", "introimage/introimage (14).jpg", "introimage/introimage (15).jpg", "introimage/introimage (16).jpg", "introimage/introimage (17).jpg", "introimage/introimage (18).jpg", "introimage/introimage (19).jpg", "introimage/introimage (20).jpg", "introimage/introimage (21).jpg", "introimage/introimage (22).jpg", "introimage/introimage (23).jpg", "introimage/introimage (24).jpg", "introimage/introimage (25).jpg", "introimage/introimage (26).jpg", "introimage/introimage (27).jpg", "introimage/introimage (28).jpg", "introimage/introimage (29).jpg", "introimage/introimage (30).jpg", "introimage/introimage (31).jpg", "introimage/introimage (32).jpg", "introimage/introimage (33).jpg", "introimage/introimage (34).jpg", "introimage/introimage (35).jpg", "introimage/introimage (36).jpg", "introimage/introimage (37).jpg", "introimage/introimage (38).jpg", "introimage/introimage (39).jpg", "introimage/introimage (40).jpg", "introimage/introimage (41).jpg", "introimage/introimage (42).jpg", "introimage/introimage (43).jpg", "introimage/introimage (44).jpg", "introimage/introimage (45).jpg", "introimage/introimage (46).jpg", "introimage/introimage (47).jpg", "introimage/introimage (48).jpg", "introimage/introimage (49).jpg", "introimage/introimage (50).jpg", "introimage/introimage (51).jpg", "introimage/introimage (52).jpg", "introimage/introimage (53).jpg", "introimage/introimage (54).jpg", "introimage/introimage (55).jpg", "introimage/introimage (56).jpg", "introimage/introimage (57).jpg", "introimage/introimage (58).jpg", "introimage/introimage (59).jpg", "introimage/introimage (60).jpg", "introimage/introimage (61).jpg", "introimage/introimage (62).jpg", "introimage/introimage (63).jpg", "introimage/introimage (64).jpg", "introimage/introimage (65).jpg", "introimage/introimage (66).jpg", "introimage/introimage (67).jpg", "introimage/introimage (68).jpg", "introimage/introimage (69).jpg", "introimage/introimage (70).jpg", "introimage/introimage (71).jpg", "introimage/introimage (72).jpg", "introimage/introimage (73).jpg", "introimage/introimage (74).jpg", "introimage/introimage (75).jpg", "introimage/introimage (76).jpg", "introimage/introimage (77).jpg", "introimage/introimage (78).jpg", "introimage/introimage (79).jpg", "introimage/introimage (80).jpg", "introimage/introimage (81).jpg", "introimage/introimage (82).jpg", "introimage/introimage (83).jpg", "introimage/introimage (84).jpg", "introimage/introimage (85).jpg", "introimage/introimage (86).jpg", "introimage/introimage (87).jpg", "introimage/introimage (88).jpg", "introimage/introimage (89).jpg", "introimage/introimage (90).jpg", "introimage/introimage (91).jpg", "introimage/introimage (92).jpg", "introimage/introimage (93).jpg", "introimage/introimage (94).jpg", "introimage/introimage (95).jpg", "introimage/introimage (96).jpg", "introimage/introimage (97).jpg", "introimage/introimage (98).jpg", "introimage/introimage (99).jpg", "introimage/introimage (100).jpg", "introimage/introimage (101).jpg", "introimage/introimage (102).jpg", "introimage/introimage (103).jpg", "introimage/introimage (104).jpg", "introimage/introimage (105).jpg", "introimage/introimage (106).jpg", "introimage/introimage (107).jpg", "introimage/introimage (108).jpg", "introimage/introimage (109).jpg", "introimage/introimage (110).jpg", "introimage/introimage (111).jpg", "introimage/introimage (112).jpg", "introimage/introimage (113).jpg", "introimage/introimage (114).jpg", "introimage/introimage (115).jpg", "introimage/introimage (116).jpg", "introimage/introimage (117).jpg", "introimage/introimage (118).jpg", "introimage/introimage (119).jpg", "introimage/introimage (120).jpg", "introimage/introimage (121).jpg", "introimage/introimage (122).jpg", "introimage/introimage (123).jpg", "introimage/introimage (124).jpg", "introimage/introimage (125).jpg", "introimage/introimage (126).jpg", "introimage/introimage (127).jpg", "introimage/introimage (128).jpg", "introimage/introimage (129).jpg", "introimage/introimage (130).jpg", "introimage/introimage (131).jpg", "introimage/introimage (132).jpg", "introimage/introimage (133).jpg", "introimage/introimage (134).jpg", "introimage/introimage (135).jpg", "introimage/introimage (136).jpg", "introimage/introimage (137).jpg", "introimage/introimage (138).jpg", "introimage/introimage (139).jpg", "introimage/introimage (140).jpg", "introimage/introimage (141).jpg", "introimage/introimage (142).jpg"};
char mazeselectorimage[8][60]={"mazeSelectorImage/SELECT MAZE.PNG","mazeSelectorImage/SELECT MAZE (7).PNG","mazeSelectorImage/SELECT MAZE (1).PNG","mazeSelectorImage/SELECT MAZE (2).PNG","mazeSelectorImage/SELECT MAZE (3).PNG","mazeSelectorImage/SELECT MAZE (4).PNG","mazeSelectorImage/SELECT MAZE (5).PNG","mazeSelectorImage/SELECT MAZE (6).PNG"};
char menuimage[8][50]={ "menu image/PACMAN.png","menu image/pacman1.png","menu image/pacman2.png","menu image/pacman3.bmp","menu image/pacman4.png","menu image/pacman5.png",
                        "menu image/pacman6.png","menu image/pacman7.png"};
 char settingsimage[8][50]={"settingsimage/settings.png","settingsimage/settings1.png","settingsimage/settings2.png","settingsimage/settings3.png","settingsimage/settings4.png",
                            "settingsimage/settings5.png","settingsimage/settings6.png","settingsimage/settings7.png"};
 char highscoreimage[2][50]={"highscoreimage/highscore (2).png","highscoreimage/highscore (1).png"};
 char creditimage[2][50]={"creditsimage/CREDITS.png","creditsimage/credits1.png"};
 char rulesimage[2][50]={"rules/RULES.png","rules/rules1.png"};
 char levelselectimage[100][50]={"level/level (1).jpg", "level/level (2).jpg", "level/level (3).jpg", "level/level (4).jpg", "level/level (5).jpg", "level/level (6).jpg", "level/level (7).jpg", "level/level (8).jpg", "level/level (9).jpg", "level/level (10).jpg", "level/level (11).jpg", "level/level (12).jpg", "level/level (13).jpg", "level/level (14).jpg", "level/level (15).jpg", "level/level (16).jpg", "level/level (17).jpg", "level/level (18).jpg", "level/level (19).jpg", "level/level (20).jpg", "level/level (21).jpg", "level/level (22).jpg", "level/level (23).jpg", "level/level (24).jpg", "level/level (25).jpg", "level/level (26).jpg", "level/level (27).jpg", "level/level (28).jpg", "level/level (29).jpg", "level/level (30).jpg", "level/level (31).jpg", "level/level (32).jpg", "level/level (33).jpg", "level/level (34).jpg", "level/level (35).jpg", "level/level (36).jpg", "level/level (37).jpg", "level/level (38).jpg", "level/level (39).jpg", "level/level (40).jpg", "level/level (41).jpg", "level/level (42).jpg", "level/level (43).jpg", "level/level (44).jpg", "level/level (45).jpg", "level/level (46).jpg", "level/level (47).jpg", "level/level (48).jpg", "level/level (49).jpg", "level/level (50).jpg", "level/level (51).jpg", "level/level (52).jpg", "level/level (53).jpg", "level/level (54).jpg", "level/level (55).jpg", "level/level (56).jpg", "level/level (57).jpg", "level/level (58).jpg", "level/level (59).jpg", "level/level (60).jpg", "level/level (61).jpg", "level/level (62).jpg", "level/level (63).jpg", "level/level (64).jpg", "level/level (65).jpg", "level/level (66).jpg", "level/level (67).jpg", "level/level (68).jpg", "level/level (69).jpg", "level/level (70).jpg", "level/level (71).jpg", "level/level (72).jpg", "level/level (73).jpg", "level/level (74).jpg", "level/level (75).jpg", "level/level (76).jpg", "level/level (77).jpg", "level/level (78).jpg", "level/level (79).jpg", "level/level (80).jpg", "level/level (81).jpg", "level/level (82).jpg", "level/level (83).jpg", "level/level (84).jpg", "level/level (85).jpg", "level/level (86).jpg", "level/level (87).jpg", "level/level (88).jpg", "level/level (89).jpg", "level/level (90).jpg", "level/level (91).jpg", "level/level (92).jpg", "level/level (93).jpg", "level/level (94).jpg", "level/level (95).jpg", "level/level (96).jpg", "level/level (97).jpg", "level/level (98).jpg", "level/level (99).jpg", "level/level (100).jpg",};
 char quitimage[3][50]={"exitimage/exitimage.png","exitimage/exitimage1.png","exitimage/exitimage2.png"};
 char difficultyimage[6][50]={"difficultyimage/Difficulty.png","difficultyimage/Difficulty1.png","difficultyimage/Difficulty2.png","difficultyimage/Difficulty3.png",
                             "difficultyimage/Difficulty4.png","difficultyimage/Difficulty5.png",};
 char mazeimage[6][50]={"mazeDesignImage/mazeDesign1.png","mazeDesignImage/mazeDesign2.png","mazeDesignImage/mazeDesign3.png","mazeDesignImage/mazeDesign4.png","mazeDesignImage/mazeDesign5.png","mazeDesignImage/mazeDesign6.png"};
 char playgameintroimage[1][50]={"playgameintro/intro.png"};
 char exitimage[100][100]={"thanksimage/thanks (1).jpg", "thanksimage/thanks (2).jpg", "thanksimage/thanks (3).jpg", "thanksimage/thanks (4).jpg", "thanksimage/thanks (5).jpg", "thanksimage/thanks (6).jpg", "thanksimage/thanks (7).jpg", "thanksimage/thanks (8).jpg", "thanksimage/thanks (9).jpg", "thanksimage/thanks (10).jpg", "thanksimage/thanks (11).jpg", "thanksimage/thanks (12).jpg", "thanksimage/thanks (13).jpg", "thanksimage/thanks (14).jpg", "thanksimage/thanks (15).jpg", "thanksimage/thanks (16).jpg", "thanksimage/thanks (17).jpg", "thanksimage/thanks (18).jpg", "thanksimage/thanks (19).jpg", "thanksimage/thanks (20).jpg", "thanksimage/thanks (21).jpg", "thanksimage/thanks (22).jpg", "thanksimage/thanks (23).jpg", "thanksimage/thanks (24).jpg", "thanksimage/thanks (25).jpg", "thanksimage/thanks (26).jpg", "thanksimage/thanks (27).jpg", "thanksimage/thanks (28).jpg", "thanksimage/thanks (29).jpg", "thanksimage/thanks (30).jpg", "thanksimage/thanks (31).jpg", "thanksimage/thanks (32).jpg", "thanksimage/thanks (33).jpg", "thanksimage/thanks (34).jpg", "thanksimage/thanks (35).jpg", "thanksimage/thanks (36).jpg", "thanksimage/thanks (37).jpg", "thanksimage/thanks (38).jpg", "thanksimage/thanks (39).jpg", "thanksimage/thanks (40).jpg", "thanksimage/thanks (41).jpg", "thanksimage/thanks (42).jpg", "thanksimage/thanks (43).jpg", "thanksimage/thanks (44).jpg", "thanksimage/thanks (45).jpg", "thanksimage/thanks (46).jpg", "thanksimage/thanks (47).jpg", "thanksimage/thanks (48).jpg", "thanksimage/thanks (49).jpg", "thanksimage/thanks (50).jpg", "thanksimage/thanks (51).jpg", "thanksimage/thanks (52).jpg", "thanksimage/thanks (53).jpg", "thanksimage/thanks (54).jpg", "thanksimage/thanks (55).jpg", "thanksimage/thanks (56).jpg", "thanksimage/thanks (57).jpg", "thanksimage/thanks (58).jpg", "thanksimage/thanks (59).jpg", "thanksimage/thanks (60).jpg", "thanksimage/thanks (61).jpg", "thanksimage/thanks (62).jpg", "thanksimage/thanks (63).jpg", "thanksimage/thanks (64).jpg", "thanksimage/thanks (65).jpg", "thanksimage/thanks (66).jpg", "thanksimage/thanks (67).jpg", "thanksimage/thanks (68).jpg", "thanksimage/thanks (69).jpg", "thanksimage/thanks (70).jpg", "thanksimage/thanks (71).jpg", "thanksimage/thanks (72).jpg", "thanksimage/thanks (73).jpg", "thanksimage/thanks (74).jpg", "thanksimage/thanks (75).jpg", "thanksimage/thanks (76).jpg", "thanksimage/thanks (77).jpg", "thanksimage/thanks (78).jpg", "thanksimage/thanks (79).jpg", "thanksimage/thanks (80).jpg", "thanksimage/thanks (81).jpg", "thanksimage/thanks (82).jpg", "thanksimage/thanks (83).jpg", "thanksimage/thanks (84).jpg", "thanksimage/thanks (85).jpg", "thanksimage/thanks (86).jpg", "thanksimage/thanks (87).jpg", "thanksimage/thanks (88).jpg", "thanksimage/thanks (89).jpg", "thanksimage/thanks (90).jpg", "thanksimage/thanks (91).jpg", "thanksimage/thanks (92).jpg", "thanksimage/thanks (93).jpg", "thanksimage/thanks (94).jpg", "thanksimage/thanks (95).jpg", "thanksimage/thanks (96).jpg", "thanksimage/thanks (97).jpg", "thanksimage/thanks (98).jpg", "thanksimage/thanks (99).jpg", "thanksimage/thanks (100).jpg",};
 char pauseimage[4][40]={"pauseimage/pause (1).png","pauseimage/pause (2).png","pauseimage/pause (3).png","pauseimage/pause (4).png",};
 char backgroundimage[5][50]={"bg/bg (1).png","bg/bg (2).png","bg/bg (3).png","bg/bg (4).png","bg/bg (5).png"};
 char backgroundselectorimage[5][50]={"slbg/slbg (5).png","slbg/slbg (3).png","slbg/slbg (4).png","slbg/slbg (2).png","slbg/slbg (1).png"};

char pacmanRight[2][30] = {"pacman/pacman (1).png","pacman/pacman (2).png"};
char pacmanLeft[2][30] ={"pacman/pacman (5).png","pacman/pacman (6).png"};
char pacmanUp[2][30] ={"pacman/pacman (7).png","pacman/pacman (8).png"};
char pacmanDown[2][30] ={"pacman/pacman (3).png","pacman/pacman (4).png"};
char *fruit[7];

char inkyUp[2][30] = {"inky/inky (2).png","inky/inky (3).png"};
char inkyLeft[2][30] = {"inky/inky (7).png","inky/inky (8).png"};
char inkyDown[2][30] = {"inky/inky (5).png","inky/inky (6).png"};
char inkyRight[2][30] ={"inky/inky (1).png","inky/inky (4).png"};

char blinkyUp[2][30] = {"blinky/blinky (2).png","blinky/blinky (3).png"};
char blinkyDown[2][30] ={"blinky/blinky (5).png","blinky/blinky (6).png"} ;
char blinkyLeft[2][30] ={"blinky/blinky (1).png","blinky/blinky (1).png"};
char blinkyRight[2][30] ={"blinky/blinky (7).png","blinky/blinky (8).png"};

char pinkyUp[2][30] = {"pinky/pinky (2).png","pinky/pinky (3).png"};
char pinkyDown[2][30] ={"pinky/pinky (5).png","pinky/pinky (6).png"};
char pinkyLeft[2][30] ={"pinky/pinky (7).png","pinky/pinky (8).png"};
char pinkyRight[2][30] = {"pinky/pinky (1).png","pinky/pinky (4).png"};

char clydeUp[2][30] ={"clyde/clyde (1).png","clyde/clyde (2).png"};
char clydeDown[2][30] ={"clyde/clyde (5).png","clyde/clyde (6).png"} ;
char clydeLeft[2][30] ={"clyde/clyde (7).png","clyde/clyde (8).png"};
char clydeRight[2][30] ={"clyde/clyde (3).png","clyde/clyde (4).png"}; 

char frozenGhost[2][40] ={"frozen/frozen (1).png","frozen/frozen (2).png"} ;
char frozenGhostEnd[2][40] ={"frozen/frozen (2).png","frozen/frozen (3).png"} ;

int maze1[21][19] =
	{
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0,
		1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
		1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1

	};
void  corrdinatestore1()
{
	int i, j;
	int dx = startx, dy =starty;
	for (i = 0; i < 21; i++){
		for (j = 0; j < 19; j++){
			map1CoordinateX[i][j] = dx;
			map1CoordinateY[i][j] = dy;
			dx += mazeWidth1;
		}
		dx = startx;
		dy -= 25;
	}
}
int maze2[21][19]=
{
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
		1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
void corrdinatestore2()
{
	int i, j;
	int dx = startx, dy =starty;
	for (i = 0; i < 21; i++){
		for (j = 0; j < 19; j++){
			map2CoordinateX[i][j] = dx;
			map2CoordinateY[i][j] = dy;
			dx += mazeWidth1;
		}
		dx = startx;
		dy -= 25;
	}
}
int maze3[17][36] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1},
  {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1},
  {1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1},
  {1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
  {1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
  {1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1},
  {1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
  {1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void  corrdinatestore3()
{
	int i, j;
	int dx = startx, dy =starty;
	for (i = 0; i < 17; i++){
		for (j = 0; j < 36; j++){
			map3CoordinateX[i][j] = dx;
			map3CoordinateY[i][j] = dy;
			dx += mazeWidth1;
		}
		dx = startx;
		dy -= 25;
	}
}
int maze4[19][40] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
  {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1},
  {1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void  corrdinatestore4()
{
	int i, j;
	int dx = startx, dy =starty;
	for (i = 0; i < 19; i++){
		for (j = 0; j < 40; j++){
			map4CoordinateX[i][j] = dx;
			map4CoordinateY[i][j] = dy;
			dx += mazeWidth1;
		}
		dx = startx;
		dy -= 25;
	}
}


void drawMaze1(){
	int i, j;
	for (i = 0; i < 21; i++){
		for (j = 0; j < 19; j++){
			if ( maze1[i][j] == 1){
				iShowImage(map1CoordinateX[i][j], map1CoordinateY[i][j], mazeimage[maze]);
			}
		}
	}
}
void drawMaze2(){
	int i, j;
	for (i = 0; i < 21; i++){
		for (j = 0; j < 19; j++){
			if ( maze2[i][j] == 1){
				iShowImage(map2CoordinateX[i][j], map2CoordinateY[i][j], mazeimage[maze]);
			}
		}
	}
}
void drawMaze3(){
	int i, j;
	for (i = 0; i < 17; i++){
		for (j = 0; j < 36; j++){
			if (maze3[i][j] == 1){
				iShowImage(map3CoordinateX[i][j], map3CoordinateY[i][j], mazeimage[maze]);
			}
		}
	}
}
void drawMaze4(){
	int i, j;
	for (i = 0; i < 19; i++){
		for (j = 0; j < 40; j++){
			if (maze4[i][j] == 1){
				iShowImage(map4CoordinateX[i][j], map4CoordinateY[i][j], mazeimage[maze]);
			}
		}
	}
}


/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
    // place your drawing codes here
    iClear();
    if(startintro)
    {
        iShowImage(0,0,introimage[intro]);
    }
    else if(mainmenu)
        {
           iShowImage(0,0,menuimage[menuc]);
        }
    else if(difficulty)
        {
          iShowImage(0,0,difficultyimage[difficultyc]);
        }
    else if(highscore)
    {
        iShowImage(0,0,highscoreimage[highscorec]);
    }
    else if(playgameintro)
    {
        iShowImage(0,0,playgameintroimage[playgamec]);

    }
    else if(settings)
        {
          iShowImage(0,0, settingsimage[settingsc]);
        }
    else if(mazeselector)
    {
        iShowImage(0,0, mazeselectorimage[mazeselectorc]);
    }
    else if(highscore)
        {
          //iShowImage();
        }
    else if(credits)
       {
        iShowImage(0, 0, creditimage[creditsc]);
       }
    else if(rules)
       {
        iShowImage(0, 0, rulesimage[rulesc]);
       }
    else if(quit)
       {
        iShowImage(0, 0, quitimage[quitc]);
       }
    else if(playingstart)
    {
        iShowImage(0,0,backgroundimage[bgimage]);
        if(selected==1){
            drawMaze1();
        }
        else if(selected==2){
            drawMaze2();
        }
        else if(selected==3){
            drawMaze3();
        }
        else if(selected==4){
            drawMaze4();
        }
    }

    else if(exitintro)
    {
        iShowImage(0,0,exitimage[exitintroimage]);
    }
    else if(levelselect)
    {
        iShowImage(0,0,levelselectimage[levelintro]);
    }
    else if(pause)
    {
         iShowImage(0,0,pauseimage[pausec]);
    }
    else if(backgroundselector)
    {
        iShowImage(0,0,backgroundselectorimage[backgroundselectorc]);
    }


};
/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    if(mainmenu)
    {
        if((mx>=335&&mx<=825) &&(my>=553&& my<=652)){
            menuc=1;
        }
       else if((mx>=442&&mx<=695) &&(my>=469&& my<=495)){
            menuc=2;
        }
       else if((mx>=439&&mx<=697)&& (my>=400&& my<=422)){
            menuc=3;
        }
        else if((mx>=432&&mx<=632) && (my>=324&& my<=348)){
            menuc=4;
        }
        else if((mx>=434&&mx<=611)&& (my>=256 &&my<=276)){
            menuc=5;
        }
        else if((mx>=435 &&mx<=570)&&(my>=183&& my<=205)){
            menuc=6;
        }
        else if((mx>=435&&mx<=542)&& (my>=103&& my<=134)){
            menuc=7;
        }
        else menuc=0;

    }
    else if(highscore)
    {
        if((mx>=1040&&mx<=1150)&&( my>=42&& my<=88)){
            highscorec=1;
        }
        else highscorec=0;
    }
    else if(difficulty)
    {
        if((mx>=468&&mx<=697)&& (my>=397&& my<=448)){
            difficultyc=1;
        }
        else if((mx>=460&&mx<=805)&& (my>=306&&my<=364)){
            difficultyc=2;
        }
        else if((mx>=454&&mx<=720)&& (my>=229&&my<=280)){
            difficultyc=3;
        }
        else if((mx>=456 &&mx<=817)&&(my>=137&& my<=200)){
            difficultyc=4;
        }
        else if((mx>=46&&mx<=233)&& (my>=82&& my<=140)){
            difficultyc=5;
        }
        else difficultyc=0;
    }
    else if(settings)
    {
     if(soundOn)
      {
        if((mx>=408&&mx<=783)&&( my>=388&& my<=439)){
            settingsc=1;
        }
        else if((mx>=380&&mx<=828)&& (my>=277&& my<=320)){
             settingsc=2;
        }
        else if((mx>=964&&mx<=1172)&& (my>=59 &&my<=115)){
            settingsc=3;
        }
        else{
            settingsc=0;
        }
      }
      if(soundOn==false)
      {
        if((mx>=408&&mx<=783)&&( my>=388&& my<=439)){
            settingsc=5;
        }
        else if((mx>=380&&mx<=828)&& (my>=277&& my<=320)){
             settingsc=6;
        }
        else if((mx>=964&&mx<=1172)&& (my>=59 &&my<=115)){
            settingsc=7;
        }
        else settingsc=4;
      }

    }
    /*else if(mazeselector)
    {
        if((mx>=242&&mx<=911)&& (my>=576&& my<=659)){
            mazeselectorc=1;
        }
        else if((mx>=50&&mx<=485)&&( my>=399&& my<=509)){
            mazeselectorc=2;
        }
        else if((mx>=45&&mx<=375)&&( my>=251&&my<=374)){
            mazeselectorc=3;
        }
        else if((mx>=52&&mx<=570)&& ( my>=97&&my<=197)){
            mazeselectorc=4;
        }
        else if((mx>625 &&mx<=1068)&&( my>=396&&my<=512)){
            mazeselectorc=5;
        }
        else if((mx>=619&&mx<=918)&&( my>=262&& my<=374)){
            mazeselectorc=6;
        }
        else if((mx>=633&&mx<=980 )&&( my>=101 &&my<=209)){
            mazeselectorc=7;
        }
        else mazeselectorc=0;
    }*/
     else if(pause)
    {
       if(mx>=257&& my>=420&&mx<=698 &&my<=494) 
       {
         pausec=1;
       }
       else if(mx>=261 &&my>=299&&mx<=534 && my<=372)
       {
          pausec=2;
       }
       else if(mx>=260&& my>=179&&mx<=697&& my<=245)
       {
          pausec=3;
       }
       else  pausec=0;
    }

    else if(rules)
    {
        if((mx>=973&&mx<=1174)&& (my>=71 &&my<=127))
        {
            rulesc=1;
        }
        else rulesc=0;
    }
    else if(credits)
    {
         if((mx>=957&& mx<=1182)&&(my>=36&& my<=104))
         {
             creditsc=1;
         }
         else creditsc=0;
    }
    else if(quit)
    {
        if((mx>=289&&mx<=415)&& (my>=245&& my<=299))
        {
            quitc=1;
        }
        else if((mx>=741&&mx<=858)&& (my>=252&& my<=302))
        {
            quitc=2;
        }
        else  quitc=0;
    }
}

/*
function iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
  printf("mx=%d my=%d",mx,my);
   if(mainmenu){

        if((mx>=335&&mx<=825) &&(my>=553&& my<=652)){

        }
       else if((mx>=442&&mx<=695) &&(my>=469&& my<=495)){
            difficulty=true;
            mainmenu=false;
        }
       else if((mx>=439&&mx<=697)&& (my>=400&& my<=422)){
            mainmenu=false;
            highscore=true;
        }
        else if((mx>=432&&mx<=632) && (my>=324&& my<=348)){
            mainmenu=false;
            settings=true;
        }
        else if((mx>=434&&mx<=611)&& (my>=256 &&my<=276)){
            mainmenu=false;
            credits=true;
        }
        else if((mx>=435 &&mx<=570)&&(my>=183&& my<=205)){
           mainmenu=false;
           rules=true;
        }
        else if((mx>=435&&mx<=542)&& (my>=103&& my<=134)){
           mainmenu=false;
           quit=true;
        }
     }
    else if(highscore)
    {
        if((mx>=1040&&mx<=1150)&&( my>=42&& my<=88)){
           highscore=false;
           mainmenu=true;
        }

    }
     else if(difficulty)
     {
        if((mx>=46&&mx<=233)&& (my>=82&& my<=140)){
            difficulty=false;
            mainmenu=true ;
        }
        else if((mx>=468&&mx<=697)&& (my>=397&& my<=448)){
            playgameintro=true;
            difficulty=false;

        }
        else if((mx>=460&&mx<=805)&& (my>=306&&my<=364)){
            playgameintro=true;
            difficulty=false;

        }
        else if((mx>=454&&mx<=720)&& (my>=229&&my<=280)){
            playgameintro=true;
            difficulty=false;

        }
        else if((mx>=456 &&mx<=817)&&(my>=137&& my<=200)){
            playgameintro=true;
            difficulty=false;

        }
     }
      if(playgameintro)
      {
         if (mx >= 300 && mx <= 600 && my >= 200 && my <= 240)
        {
            typingName = true;
        }
        else if((mx>=18 && mx<=161)&&(my>=36&& my<=87))
        {
            playgameintro=false;
            difficulty=true;
        }
      }
     else if(settings)
     {
         if(soundOn)
         {
          if((mx>=408&&mx<=783)&&( my>=388&& my<=439)){
            soundOn=false;
          }
          else if((mx>=380&&mx<=828)&& (my>=277&& my<=320)){
              mazeselector=true;
              settings=false;
          }
          else if((mx>=964&&mx<=1172)&& (my>=59 &&my<=115)){
           settings=false;
            mainmenu=true;
          }

        }
        else
        {
          if((mx>=408&&mx<=783)&&( my>=388&& my<=439)){
            soundOn=true;
          }
          else if((mx>=380&&mx<=828)&& (my>=277&& my<=320)){
              mazeselector=true;
              settings=false;
          }
          else if((mx>=964&&mx<=1172)&& (my>=59 &&my<=115)){
           settings=false;
           mainmenu=true;
          }

        }

     }


    else if(mazeselector)
    {
        if((mx>=242&&mx<=911)&& (my>=576&& my<=659)){
            mazeselectorc=1;
            maze=0;
            mazeselector=false;
            settings=true;
        }
        else if((mx>=50&&mx<=485)&&( my>=399&& my<=509)){
            mazeselectorc=2;
            maze=1;
            mazeselector=false;
            settings=true;
        }
        else if((mx>=45&&mx<=375)&&( my>=251&&my<=374)){
            mazeselectorc=3;
            mazeselector=false;
            maze=2;
            settings=true;
        }
        else if((mx>=52&&mx<=570)&& ( my>=97&&my<=197)){
            mazeselectorc=4;
            mazeselector=false;
            settings=true;
            maze=3;
        }
        else if((mx>625 &&mx<=1068)&&( my>=396&&my<=512)){
            mazeselectorc=5;
            mazeselector=false;
            settings=true;
            maze=4;
        }
        else if((mx>=619&&mx<=918)&&( my>=262&& my<=374)){
            mazeselectorc=6;
           mazeselector=false;
            settings=true;
            maze=5;
        }
        else if((mx>=633&&mx<=980 )&&( my>=101 &&my<=209)){
            mazeselectorc=7;
            mazeselector=false;
            settings=true;
        }


    }
    else if(rules)
    {
        if((mx>=973&&mx<=1174)&& (my>=71 &&my<=127))
        {
            rules=false;
            mainmenu=true;
        }
    }
    else if(credits)
    {

         if((mx>=957&& mx<=1182)&&(my>=36&& my<=104))
         {
             credits=false;
             mainmenu=true;
         }
    }
    else if(levelselect)
    {
         if((mx>=455&&mx<=659)&&( my>=425 &&my<=492))
         {
             selected=1;
             levelselect=false;
             playingstart=true;
         }
         else if((mx<=653&&mx>=454 )&&( my<=388&& my>=331))
         {
             selected=2;
             levelselect=false;
             playingstart=true;

         }
         else if((mx>=453 &&my>=229&&mx<=655 &&my<=280))
         {
             selected=3;
             levelselect=false;
             playingstart=true;

         }
         else if(mx<=664&& my<=180&&mx>=444&& my>=126)
         {
             selected=3;
             levelselect=false;
             playingstart=true;
         }

    }
    else if(quit)
    {
         if((mx>=289&&mx<=415)&& (my>=245&& my<=299))
        {
            exitintro=true;
            quit=false;
        }
        else if((mx>=741&&mx<=858)&& (my>=252&& my<=302))
        {
            quitc=0;
            quit=false;
            mainmenu=true;
        }
    }
    else if(pause)
    {
       if(mx>=257&& my>=420&&mx<=698 &&my<=494) 
       {
          pause=false;
          mainmenu=true;
       }
       else if(mx>=261 &&my>=299&&mx<=534 && my<=372)
       {
           playingstart=true;
           pause=false;
       }
       else if(mx>=260&& my>=179&&mx<=697&& my<=245)
       {
          backgroundselector=true;
          pause= false;

        }
    }
    else if(playingstart)
    {
        if(mx>=26&& my>=586&&mx<=182 &&my<=634)
        {
            iPauseTimer(0);
            pause=true;
            playingstart=false;
        }
    }
    else if(backgroundselector)
    {  
      if(mx>=429 &&my>=489&&mx<=689&& my<=536)
      {
        backgroundselectorc=0;
        bgimage=0;
        backgroundselector=false;
        pause=true;
      }
      else if(mx>=434 &&my>=398&&mx<=680 &&my<=450)
      {
        backgroundselectorc=1;
        bgimage=1;
        backgroundselector=false;
        pause=true;
      }
      else if(mx>=434 &&my>=318&&mx<=612&& my<=363)
      {
        backgroundselectorc=2;
        bgimage=2;
        backgroundselector=false;
        pause=true;
      }
      else if(mx>=440&& my>=235&&mx<=636 &&my<=277)
      {
        backgroundselectorc=3;
        bgimage=3;
        backgroundselector=false;
        pause=true;
      }
      else if(mx>=432 &&my>=142&&mx<=655 &&my<=193)
      {
        backgroundselectorc=4;
        bgimage=4;
        backgroundselector=false;
        pause=true;
      }
    }

 }


    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
    }
  
};

/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(startintro){
        if(key== 13)
        {
            startintro=false;
            mainmenu=true;
        }
    }
    else if(playgameintro)
    {
        if(key== 13)
        {
           levelselect=true;
            playgameintro=false;
        }
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{
    switch (key)
    {
    case GLUT_KEY_END:
        // do something
        break;
    // place your codes for other keys here
    default:
        break;
    }
}
void introchange()
{
	if (startintro)
	{
		intro++;
		if (intro > 141)
		{
			intro = 0;
			startintro = false;
            mainmenu=true;
			iPauseTimer(0);
		}
	}
}

void exit()
{
	if (exitintro)
	{
		exitintroimage++;
		if (exitintroimage > 99)
		{
			exitintroimage = 0;
			exit(0);

		}
	}
}
void level()
{
	if (levelselect)
	{
		levelintro++;
		if (levelintro > 99)
		{
			levelintro = 0;
			iPauseTimer(0);

		}
	}
}
int main(int argc, char *argv[])
{
     glutInit(&argc, argv);
     corrdinatestore1();
	 corrdinatestore2();
	 corrdinatestore3();
	 corrdinatestore4();
    iSetTimer(30, introchange);
    iSetTimer(30, exit);
    iSetTimer(30, level);
    iInitialize(1200, 675, "PACMAN");
    return 0;
}
