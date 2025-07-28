#include "iGraphics.h"
#include "iFont.h"
#include "iSound.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

void pookieinitialcoordinate();
char *converter(int num, char *str);
void foodCoordinateStore();
int calculateDistance(int x1, int y1, int x2, int y2);
void drawFoodAndPowerPellet();
void pookiemovement();
void pacmanmovement();
void iResumeAll();
void iPauseAll();
void bluetimecheck();
void DataAnalysis();
void foodcount();
void PacmanInitialCoordinate();
void collisioncheck();
void directionGenerator();
void directionGenerator2();
void getGhostTarget(int pookietype, int *px, int *py);
void Reset();
void deathScene();
void levelShow();
void background();
void exitSequence();
void scoreshow();
void introchange();
void corrdinatestore1();
void corrdinatestore2();
void corrdinatestore3();
void corrdinatestore4();
void drawMaze1();
void drawMaze2();
void drawMaze3();
void drawMaze4();
void loadGameStat();
void storeGameStat();
void replaceUnderscoreWithSpace();
void resumeGameSession();

int mazeCellWidth = 24;
int mazeCellHeight = 24;
int startx3 = 72;
int starty3 = 480;
int startx4 = 72;
int starty4 = 528;
int startX12 = 168;
int startY12 = 528;
int map1CoordinateX[21][21];
int map1CoordinateY[21][21];
int map2CoordinateX[21][21];
int map2CoordinateY[21][21];
int map3CoordinateX[19][36];
int map3CoordinateY[19][36];
int map4CoordinateX[21][40];
int map4CoordinateY[21][40];
int foodXcor[1000][2];
int foodYcor[1000];
int mazeWidth;
int mazeHeight;
int First = 0;

int timeToGenerateFood = 350;
int t;
int *foodCor = &t;
int randGen;
int foodhelp;
int fruitGen[1001];
int blueScore;
int totalfood = 40;
int fruitTimeInterval = 600;

int cellX;
int cellY;
int menuc = 0;
int playgamec = 0;
int difficultyc = 0;
int highscorec = 0;
int mazeselectorc = 0;
int settingsc = 0;
int creditsc = 0;
int rulesc = 0;
int quitc = 0;
int congratsc = 0;
int selected;
int levelintro = 0;
int pausec = 0;
int backgroundselectorc = 0;
int bgimage = 6;
int slbgimage = 1;
int rulescene = 0;
int resumec = 0;
int loadc = 0;
int mazeX;
int mazeY;
int line;

int maze = 0;
int intro = 0;
int exitintroimage = 0;
int ratul = 0;
char namestr[100];
char playername[100];

char **name;
int *point;
int len;
int typingName = 0;
int score;
char pacScore[20] = "00";
char temp[20];

int pacmanlife = 3;
int pacdead = 0;
int pacspeed = 3;
int deadSceneCount = 0;
int deadsound = 0;
int blueGhost;
int diffSpeed = 2;
int foodNum = 5;
int scatter = 1;
int chase;

int soundOn = 1;
int startintro = 1;
int specialthanks;
int exitintro;
int mainmenu;
int difficulty;
int playgameintro;
int highscore;
int settings;
int credits;
int rules;
int quit;
int mazeselector;
int playingstart;
int levelselect;
int pause;
int backgroundselector;
int deadscene;
int congrats;
int blast;
int rulesOption;
int back = 0;
int resumeimage;
int load;

int sound1;
int sound2;
int sound3;
int sound4;
int times = 0;

typedef struct
{
    int upInd, downInd, leftInd, rightInd;
    int x;
    int y;
    int upCount, downCount, leftCount, rightCount;
    int smoothRight, smoothLeft, smoothUp, smoothDown;
    int right, left, up, down;
} pacmove;

pacmove pac;

typedef struct
{
    int upInd, downInd, leftInd, rightInd;
    int x;
    int y;
    int cellX, cellY;
    int flagRight, flagLeft, flagUp, flagDown;
    int left, right, up, down;
    int speed;
    int blueOn;
} ghost;

ghost pookie[6];

char introimage[115][50] = {"introimage/introimage (1).jpg", "introimage/introimage (2).jpg", "introimage/introimage (3).jpg", "introimage/introimage (4).jpg", "introimage/introimage (5).jpg", "introimage/introimage (6).jpg", "introimage/introimage (7).jpg", "introimage/introimage (8).jpg", "introimage/introimage (9).jpg", "introimage/introimage (10).jpg", "introimage/introimage (11).jpg", "introimage/introimage (12).jpg", "introimage/introimage (13).jpg", "introimage/introimage (14).jpg", "introimage/introimage (15).jpg", "introimage/introimage (16).jpg", "introimage/introimage (17).jpg", "introimage/introimage (18).jpg", "introimage/introimage (20).jpg", "introimage/introimage (20).jpg", "introimage/introimage (21).jpg", "introimage/introimage (22).jpg", "introimage/introimage (23).jpg", "introimage/introimage (24).jpg", "introimage/introimage (25).jpg", "introimage/introimage (26).jpg", "introimage/introimage (27).jpg", "introimage/introimage (28).jpg", "introimage/introimage (29).jpg", "introimage/introimage (30).jpg", "introimage/introimage (31).jpg", "introimage/introimage (32).jpg", "introimage/introimage (33).jpg", "introimage/introimage (34).jpg", "introimage/introimage (35).jpg", "introimage/introimage (36).jpg", "introimage/introimage (37).jpg", "introimage/introimage (38).jpg", "introimage/introimage (39).jpg", "introimage/introimage (40).jpg", "introimage/introimage (41).jpg", "introimage/introimage (42).jpg", "introimage/introimage (43).jpg", "introimage/introimage (44).jpg", "introimage/introimage (45).jpg", "introimage/introimage (46).jpg", "introimage/introimage (47).jpg", "introimage/introimage (48).jpg", "introimage/introimage (49).jpg", "introimage/introimage (50).jpg", "introimage/introimage (51).jpg", "introimage/introimage (52).jpg", "introimage/introimage (53).jpg", "introimage/introimage (54).jpg", "introimage/introimage (55).jpg", "introimage/introimage (56).jpg", "introimage/introimage (57).jpg", "introimage/introimage (58).jpg", "introimage/introimage (59).jpg", "introimage/introimage (60).jpg", "introimage/introimage (61).jpg", "introimage/introimage (62).jpg", "introimage/introimage (63).jpg", "introimage/introimage (64).jpg", "introimage/introimage (65).jpg", "introimage/introimage (66).jpg", "introimage/introimage (67).jpg", "introimage/introimage (68).jpg", "introimage/introimage (69).jpg", "introimage/introimage (70).jpg", "introimage/introimage (71).jpg", "introimage/introimage (72).jpg", "introimage/introimage (73).jpg", "introimage/introimage (74).jpg", "introimage/introimage (75).jpg", "introimage/introimage (76).jpg", "introimage/introimage (77).jpg", "introimage/introimage (78).jpg", "introimage/introimage (79).jpg", "introimage/introimage (80).jpg", "introimage/introimage (81).jpg", "introimage/introimage (82).jpg", "introimage/introimage (83).jpg", "introimage/introimage (84).jpg", "introimage/introimage (85).jpg", "introimage/introimage (86).jpg", "introimage/introimage (87).jpg", "introimage/introimage (88).jpg", "introimage/introimage (89).jpg", "introimage/introimage (90).jpg", "introimage/introimage (91).jpg", "introimage/introimage (92).jpg", "introimage/introimage (93).jpg", "introimage/introimage (94).jpg", "introimage/introimage (95).jpg", "introimage/introimage (96).jpg", "introimage/introimage (97).jpg", "introimage/introimage (98).jpg", "introimage/introimage (99).jpg", "introimage/introimage (100).jpg", "introimage/introimage (101).jpg", "introimage/introimage (102).jpg", "introimage/introimage (103).jpg", "introimage/introimage (104).jpg", "introimage/introimage (105).jpg", "introimage/introimage (106).jpg", "introimage/introimage (107).jpg", "introimage/introimage (108).jpg", "introimage/introimage (109).jpg", "introimage/introimage (110).jpg", "introimage/introimage (111).jpg", "introimage/introimage (112).jpg", "introimage/introimage (113).jpg", "introimage/introimage (114).jpg", "introimage/introimage (115).jpg"};
char mazeselectorimage[8][60] = {"mazeSelectorImage/pixel.PNG", "mazeSelectorImage/nebula.PNG", "mazeSelectorImage/spectral.PNG", "mazeSelectorImage/psi.PNG", "mazeSelectorImage/crack.PNG", "mazeSelectorImage/echo.PNG", "mazeSelectorImage/phantom.PNG", "mazeSelectorImage/spiral.PNG"};
char menuimage[9][50] = {"menu image/PACMAN.png", "menu image/pacman1.png", "menu image/pacman2.png", "menu image/pacman3.png", "menu image/pacman4.png", "menu image/pacman5.png", "menu image/pacman6.png", "menu image/pacman7.png", "menu image/pacman8.png"};
char settingsimage[8][50] = {"settingsimage/settings.png", "settingsimage/settings1.png", "settingsimage/settings2.png", "settingsimage/settings3.png", "settingsimage/settings4.png", "settingsimage/settings5.png", "settingsimage/settings6.png", "settingsimage/settings7.png"};
char highscoreimage[2][50] = {"highscoreimage/highscore (2).png", "highscoreimage/highscore (1).png"};
char creditimage[2][50] = {"creditsimage/CREDITS.png", "creditsimage/credits1.png"};
char rulesimage[250][50] = {"rules/rule (1).jpg", "rules/rule (2).jpg", "rules/rule (3).jpg", "rules/rule (4).jpg", "rules/rule (5).jpg", "rules/rule (6).jpg", "rules/rule (7).jpg", "rules/rule (8).jpg", "rules/rule (9).jpg", "rules/rule (10).jpg", "rules/rule (11).jpg", "rules/rule (12).jpg", "rules/rule (13).jpg", "rules/rule (14).jpg", "rules/rule (15).jpg", "rules/rule (16).jpg", "rules/rule (17).jpg", "rules/rule (18).jpg", "rules/rule (19).jpg", "rules/rule (20).jpg", "rules/rule (21).jpg", "rules/rule (22).jpg", "rules/rule (23).jpg", "rules/rule (24).jpg", "rules/rule (25).jpg", "rules/rule (26).jpg", "rules/rule (27).jpg", "rules/rule (28).jpg", "rules/rule (29).jpg", "rules/rule (30).jpg", "rules/rule (31).jpg", "rules/rule (32).jpg", "rules/rule (33).jpg", "rules/rule (34).jpg", "rules/rule (35).jpg", "rules/rule (36).jpg", "rules/rule (37).jpg", "rules/rule (38).jpg", "rules/rule (39).jpg", "rules/rule (40).jpg", "rules/rule (41).jpg", "rules/rule (42).jpg", "rules/rule (43).jpg", "rules/rule (44).jpg", "rules/rule (45).jpg", "rules/rule (46).jpg", "rules/rule (47).jpg", "rules/rule (48).jpg", "rules/rule (49).jpg", "rules/rule (50).jpg", "rules/rule (51).jpg", "rules/rule (52).jpg", "rules/rule (53).jpg", "rules/rule (54).jpg", "rules/rule (55).jpg", "rules/rule (56).jpg", "rules/rule (57).jpg", "rules/rule (58).jpg", "rules/rule (59).jpg", "rules/rule (60).jpg", "rules/rule (61).jpg", "rules/rule (62).jpg", "rules/rule (63).jpg", "rules/rule (64).jpg", "rules/rule (65).jpg", "rules/rule (66).jpg", "rules/rule (67).jpg", "rules/rule (68).jpg", "rules/rule (69).jpg", "rules/rule (70).jpg", "rules/rule (71).jpg", "rules/rule (72).jpg", "rules/rule (73).jpg", "rules/rule (74).jpg", "rules/rule (75).jpg", "rules/rule (76).jpg", "rules/rule (77).jpg", "rules/rule (78).jpg", "rules/rule (79).jpg", "rules/rule (80).jpg", "rules/rule (81).jpg", "rules/rule (82).jpg", "rules/rule (83).jpg", "rules/rule (84).jpg", "rules/rule (85).jpg", "rules/rule (86).jpg", "rules/rule (87).jpg", "rules/rule (88).jpg", "rules/rule (89).jpg", "rules/rule (90).jpg", "rules/rule (91).jpg", "rules/rule (92).jpg", "rules/rule (93).jpg", "rules/rule (94).jpg", "rules/rule (95).jpg", "rules/rule (96).jpg", "rules/rule (97).jpg", "rules/rule (98).jpg", "rules/rule (99).jpg", "rules/rule (100).jpg", "rules/rule (101).jpg", "rules/rule (102).jpg", "rules/rule (103).jpg", "rules/rule (104).jpg", "rules/rule (105).jpg", "rules/rule (106).jpg", "rules/rule (107).jpg", "rules/rule (108).jpg", "rules/rule (109).jpg", "rules/rule (110).jpg", "rules/rule (111).jpg", "rules/rule (112).jpg", "rules/rule (113).jpg", "rules/rule (114).jpg", "rules/rule (115).jpg", "rules/rule (116).jpg", "rules/rule (117).jpg", "rules/rule (118).jpg", "rules/rule (119).jpg", "rules/rule (120).jpg", "rules/rule (121).jpg", "rules/rule (122).jpg", "rules/rule (123).jpg", "rules/rule (124).jpg", "rules/rule (125).jpg", "rules/rule (126).jpg", "rules/rule (127).jpg", "rules/rule (128).jpg", "rules/rule (129).jpg", "rules/rule (130).jpg", "rules/rule (131).jpg", "rules/rule (132).jpg", "rules/rule (133).jpg", "rules/rule (134).jpg", "rules/rule (135).jpg", "rules/rule (136).jpg", "rules/rule (137).jpg", "rules/rule (138).jpg", "rules/rule (139).jpg", "rules/rule (140).jpg", "rules/rule (141).jpg", "rules/rule (142).jpg", "rules/rule (143).jpg", "rules/rule (144).jpg", "rules/rule (145).jpg", "rules/rule (146).jpg", "rules/rule (147).jpg", "rules/rule (148).jpg", "rules/rule (149).jpg", "rules/rule (150).jpg", "rules/rule (151).jpg", "rules/rule (152).jpg", "rules/rule (153).jpg", "rules/rule (154).jpg", "rules/rule (155).jpg", "rules/rule (156).jpg", "rules/rule (157).jpg", "rules/rule (158).jpg", "rules/rule (159).jpg", "rules/rule (160).jpg", "rules/rule (161).jpg", "rules/rule (162).jpg", "rules/rule (163).jpg", "rules/rule (164).jpg", "rules/rule (165).jpg", "rules/rule (166).jpg", "rules/rule (167).jpg", "rules/rule (168).jpg", "rules/rule (169).jpg", "rules/rule (170).jpg", "rules/rule (171).jpg", "rules/rule (172).jpg", "rules/rule (173).jpg", "rules/rule (174).jpg", "rules/rule (175).jpg", "rules/rule (176).jpg", "rules/rule (177).jpg", "rules/rule (178).jpg", "rules/rule (179).jpg", "rules/rule (180).jpg", "rules/rule (181).jpg", "rules/rule (182).jpg", "rules/rule (183).jpg", "rules/rule (184).jpg", "rules/rule (185).jpg", "rules/rule (186).jpg", "rules/rule (187).jpg", "rules/rule (188).jpg", "rules/rule (189).jpg", "rules/rule (190).jpg", "rules/rule (191).jpg", "rules/rule (192).jpg", "rules/rule (193).jpg", "rules/rule (194).jpg", "rules/rule (195).jpg", "rules/rule (196).jpg", "rules/rule (197).jpg", "rules/rule (198).jpg", "rules/rule (199).jpg", "rules/rule (200).jpg", "rules/rule (201).jpg", "rules/rule (202).jpg", "rules/rule (203).jpg", "rules/rule (204).jpg", "rules/rule (205).jpg", "rules/rule (206).jpg", "rules/rule (207).jpg", "rules/rule (208).jpg", "rules/rule (209).jpg", "rules/rule (210).jpg", "rules/rule (211).jpg", "rules/rule (212).jpg", "rules/rule (213).jpg", "rules/rule (214).jpg", "rules/rule (215).jpg", "rules/rule (216).jpg", "rules/rule (217).jpg", "rules/rule (218).jpg", "rules/rule (219).jpg", "rules/rule (220).jpg", "rules/rule (221).jpg", "rules/rule (222).jpg", "rules/rule (223).jpg", "rules/rule (224).jpg", "rules/rule (225).jpg", "rules/rule (226).jpg", "rules/rule (227).jpg", "rules/rule (228).jpg", "rules/rule (229).jpg", "rules/rule (230).jpg", "rules/rule (231).jpg", "rules/rule (232).jpg", "rules/rule (233).jpg", "rules/rule (234).jpg", "rules/rule (235).jpg", "rules/rule (236).jpg", "rules/rule (237).jpg", "rules/rule (238).jpg", "rules/rule (239).jpg", "rules/rule (240).jpg", "rules/rule (241).jpg", "rules/rule (242).jpg", "rules/rule (243).jpg", "rules/rule (244).jpg", "rules/rule (245).jpg", "rules/rule (246).jpg", "rules/rule (247).jpg", "rules/rule (248).jpg", "rules/rule (249).jpg", "rules/rule (250).jpg"};
char levelselectimage[100][50] = {"level/level (1).jpg", "level/level (2).jpg", "level/level (3).jpg", "level/level (4).jpg", "level/level (5).jpg", "level/level (6).jpg", "level/level (7).jpg", "level/level (8).jpg", "level/level (9).jpg", "level/level (10).jpg", "level/level (11).jpg", "level/level (12).jpg", "level/level (13).jpg", "level/level (14).jpg", "level/level (15).jpg", "level/level (16).jpg", "level/level (17).jpg", "level/level (18).jpg", "level/level (20).jpg", "level/level (20).jpg", "level/level (21).jpg", "level/level (22).jpg", "level/level (23).jpg", "level/level (24).jpg", "level/level (25).jpg", "level/level (26).jpg", "level/level (27).jpg", "level/level (28).jpg", "level/level (29).jpg", "level/level (30).jpg", "level/level (31).jpg", "level/level (32).jpg", "level/level (33).jpg", "level/level (34).jpg", "level/level (35).jpg", "level/level (36).jpg", "level/level (37).jpg", "level/level (38).jpg", "level/level (39).jpg", "level/level (40).jpg", "level/level (41).jpg", "level/level (42).jpg", "level/level (43).jpg", "level/level (44).jpg", "level/level (45).jpg", "level/level (46).jpg", "level/level (47).jpg", "level/level (48).jpg", "level/level (49).jpg", "level/level (50).jpg", "level/level (51).jpg", "level/level (52).jpg", "level/level (53).jpg", "level/level (54).jpg", "level/level (55).jpg", "level/level (56).jpg", "level/level (57).jpg", "level/level (58).jpg", "level/level (59).jpg", "level/level (60).jpg", "level/level (61).jpg", "level/level (62).jpg", "level/level (63).jpg", "level/level (64).jpg", "level/level (65).jpg", "level/level (66).jpg", "level/level (67).jpg", "level/level (68).jpg", "level/level (69).jpg", "level/level (70).jpg", "level/level (71).jpg", "level/level (72).jpg", "level/level (73).jpg", "level/level (74).jpg", "level/level (75).jpg", "level/level (76).jpg", "level/level (77).jpg", "level/level (78).jpg", "level/level (79).jpg", "level/level (80).jpg", "level/level (81).jpg", "level/level (82).jpg", "level/level (83).jpg", "level/level (84).jpg", "level/level (85).jpg", "level/level (86).jpg", "level/level (87).jpg", "level/level (88).jpg", "level/level (89).jpg", "level/level (90).jpg", "level/level (91).jpg", "level/level (92).jpg", "level/level (93).jpg", "level/level (94).jpg", "level/level (95).jpg", "level/level (96).jpg", "level/level (97).jpg", "level/level (98).jpg", "level/level (99).jpg", "level/level (100).jpg"};
char quitimage[3][50] = {"exitimage/exitimage.png", "exitimage/exitimage1.png", "exitimage/exitimage2.png"};
char difficultyimage[5][50] = {"difficultyimage/DIFFICULTY (1).png", "difficultyimage/DIFFICULTY (2).png", "difficultyimage/DIFFICULTY (3).png", "difficultyimage/DIFFICULTY (4).png"};
char mazeimage[8][50] = {"mazeDesignImage/pixel.png", "mazeDesignImage/nebula.png", "mazeDesignImage/spectral.png", "mazeDesignImage/psi.png", "mazeDesignImage/crack.png", "mazeDesignImage/echo.png", "mazeDesignImage/phantom.png", "mazeDesignImage/spiral.png"};
char playgameintroimage[2][50] = {"playgameintro/intro.png", "playgameintro/intro2.png"};
char exitimage[100][100] = {"thanksimage/thanks (1).jpg", "thanksimage/thanks (2).jpg", "thanksimage/thanks (3).jpg", "thanksimage/thanks (4).jpg", "thanksimage/thanks (5).jpg", "thanksimage/thanks (6).jpg", "thanksimage/thanks (7).jpg", "thanksimage/thanks (8).jpg", "thanksimage/thanks (9).jpg", "thanksimage/thanks (10).jpg", "thanksimage/thanks (11).jpg", "thanksimage/thanks (12).jpg", "thanksimage/thanks (13).jpg", "thanksimage/thanks (14).jpg", "thanksimage/thanks (15).jpg", "thanksimage/thanks (16).jpg", "thanksimage/thanks (17).jpg", "thanksimage/thanks (18).jpg", "thanksimage/thanks (20).jpg", "thanksimage/thanks (20).jpg", "thanksimage/thanks (21).jpg", "thanksimage/thanks (22).jpg", "thanksimage/thanks (23).jpg", "thanksimage/thanks (24).jpg", "thanksimage/thanks (25).jpg", "thanksimage/thanks (26).jpg", "thanksimage/thanks (27).jpg", "thanksimage/thanks (28).jpg", "thanksimage/thanks (29).jpg", "thanksimage/thanks (30).jpg", "thanksimage/thanks (31).jpg", "thanksimage/thanks (32).jpg", "thanksimage/thanks (33).jpg", "thanksimage/thanks (34).jpg", "thanksimage/thanks (35).jpg", "thanksimage/thanks (36).jpg", "thanksimage/thanks (37).jpg", "thanksimage/thanks (38).jpg", "thanksimage/thanks (39).jpg", "thanksimage/thanks (40).jpg", "thanksimage/thanks (41).jpg", "thanksimage/thanks (42).jpg", "thanksimage/thanks (43).jpg", "thanksimage/thanks (44).jpg", "thanksimage/thanks (45).jpg", "thanksimage/thanks (46).jpg", "thanksimage/thanks (47).jpg", "thanksimage/thanks (48).jpg", "thanksimage/thanks (49).jpg", "thanksimage/thanks (50).jpg", "thanksimage/thanks (51).jpg", "thanksimage/thanks (52).jpg", "thanksimage/thanks (53).jpg", "thanksimage/thanks (54).jpg", "thanksimage/thanks (55).jpg", "thanksimage/thanks (56).jpg", "thanksimage/thanks (57).jpg", "thanksimage/thanks (58).jpg", "thanksimage/thanks (59).jpg", "thanksimage/thanks (60).jpg", "thanksimage/thanks (61).jpg", "thanksimage/thanks (62).jpg", "thanksimage/thanks (63).jpg", "thanksimage/thanks (64).jpg", "thanksimage/thanks (65).jpg", "thanksimage/thanks (66).jpg", "thanksimage/thanks (67).jpg", "thanksimage/thanks (68).jpg", "thanksimage/thanks (69).jpg", "thanksimage/thanks (70).jpg", "thanksimage/thanks (71).jpg", "thanksimage/thanks (72).jpg", "thanksimage/thanks (73).jpg", "thanksimage/thanks (74).jpg", "thanksimage/thanks (75).jpg", "thanksimage/thanks (76).jpg", "thanksimage/thanks (77).jpg", "thanksimage/thanks (78).jpg", "thanksimage/thanks (79).jpg", "thanksimage/thanks (80).jpg", "thanksimage/thanks (81).jpg", "thanksimage/thanks (82).jpg", "thanksimage/thanks (83).jpg", "thanksimage/thanks (84).jpg", "thanksimage/thanks (85).jpg", "thanksimage/thanks (86).jpg", "thanksimage/thanks (87).jpg", "thanksimage/thanks (88).jpg", "thanksimage/thanks (89).jpg", "thanksimage/thanks (90).jpg", "thanksimage/thanks (91).jpg", "thanksimage/thanks (92).jpg", "thanksimage/thanks (93).jpg", "thanksimage/thanks (94).jpg", "thanksimage/thanks (95).jpg", "thanksimage/thanks (96).jpg", "thanksimage/thanks (97).jpg", "thanksimage/thanks (98).jpg", "thanksimage/thanks (99).jpg", "thanksimage/thanks (100).jpg"};
char pauseimage[4][40] = {"pauseimage/pause (1).png", "pauseimage/pause (2).png", "pauseimage/pause (3).png", "pauseimage/pause (4).png"};
char backgroundimage[7][50] = {"bg/bg.png", "bg/bg (1).png", "bg/bg (2).png", "bg/bg (3).png", "bg/bg (4).png", "bg/bg (5).png", "bg/bggg.png"};
char slbg1[100][30] = {"slbg1/slbg1 (1).jpg", "slbg1/slbg1 (2).jpg", "slbg1/slbg1 (3).jpg", "slbg1/slbg1 (4).jpg", "slbg1/slbg1 (5).jpg", "slbg1/slbg1 (6).jpg", "slbg1/slbg1 (7).jpg", "slbg1/slbg1 (8).jpg", "slbg1/slbg1 (9).jpg", "slbg1/slbg1 (10).jpg", "slbg1/slbg1 (11).jpg", "slbg1/slbg1 (12).jpg", "slbg1/slbg1 (13).jpg", "slbg1/slbg1 (14).jpg", "slbg1/slbg1 (15).jpg", "slbg1/slbg1 (16).jpg", "slbg1/slbg1 (17).jpg", "slbg1/slbg1 (18).jpg", "slbg1/slbg1 (19).jpg", "slbg1/slbg1 (20).jpg", "slbg1/slbg1 (21).jpg", "slbg1/slbg1 (22).jpg", "slbg1/slbg1 (23).jpg", "slbg1/slbg1 (24).jpg", "slbg1/slbg1 (25).jpg", "slbg1/slbg1 (26).jpg", "slbg1/slbg1 (27).jpg", "slbg1/slbg1 (28).jpg", "slbg1/slbg1 (29).jpg", "slbg1/slbg1 (30).jpg", "slbg1/slbg1 (31).jpg", "slbg1/slbg1 (32).jpg", "slbg1/slbg1 (33).jpg", "slbg1/slbg1 (34).jpg", "slbg1/slbg1 (35).jpg", "slbg1/slbg1 (36).jpg", "slbg1/slbg1 (37).jpg", "slbg1/slbg1 (38).jpg", "slbg1/slbg1 (39).jpg", "slbg1/slbg1 (40).jpg", "slbg1/slbg1 (41).jpg", "slbg1/slbg1 (42).jpg", "slbg1/slbg1 (43).jpg", "slbg1/slbg1 (44).jpg", "slbg1/slbg1 (45).jpg", "slbg1/slbg1 (46).jpg", "slbg1/slbg1 (47).jpg", "slbg1/slbg1 (48).jpg", "slbg1/slbg1 (49).jpg", "slbg1/slbg1 (50).jpg", "slbg1/slbg1 (51).jpg", "slbg1/slbg1 (52).jpg", "slbg1/slbg1 (53).jpg", "slbg1/slbg1 (54).jpg", "slbg1/slbg1 (55).jpg", "slbg1/slbg1 (56).jpg", "slbg1/slbg1 (57).jpg", "slbg1/slbg1 (58).jpg", "slbg1/slbg1 (59).jpg", "slbg1/slbg1 (60).jpg", "slbg1/slbg1 (61).jpg", "slbg1/slbg1 (62).jpg", "slbg1/slbg1 (63).jpg", "slbg1/slbg1 (64).jpg", "slbg1/slbg1 (65).jpg", "slbg1/slbg1 (66).jpg", "slbg1/slbg1 (67).jpg", "slbg1/slbg1 (68).jpg", "slbg1/slbg1 (69).jpg", "slbg1/slbg1 (70).jpg", "slbg1/slbg1 (71).jpg", "slbg1/slbg1 (72).jpg", "slbg1/slbg1 (73).jpg", "slbg1/slbg1 (74).jpg", "slbg1/slbg1 (75).jpg", "slbg1/slbg1 (76).jpg", "slbg1/slbg1 (77).jpg", "slbg1/slbg1 (78).jpg", "slbg1/slbg1 (79).jpg", "slbg1/slbg1 (80).jpg", "slbg1/slbg1 (81).jpg", "slbg1/slbg1 (82).jpg", "slbg1/slbg1 (83).jpg", "slbg1/slbg1 (84).jpg", "slbg1/slbg1 (85).jpg", "slbg1/slbg1 (86).jpg", "slbg1/slbg1 (87).jpg", "slbg1/slbg1 (88).jpg", "slbg1/slbg1 (89).jpg", "slbg1/slbg1 (90).jpg", "slbg1/slbg1 (91).jpg", "slbg1/slbg1 (92).jpg", "slbg1/slbg1 (93).jpg", "slbg1/slbg1 (94).jpg", "slbg1/slbg1 (95).jpg", "slbg1/slbg1 (96).jpg", "slbg1/slbg1 (97).jpg", "slbg1/slbg1 (98).jpg", "slbg1/slbg1 (99).jpg", "slbg1/slbg1 (100).jpg"};
char slbg2[100][30] = {"slbg2/slbg2 (1).jpg", "slbg2/slbg2 (2).jpg", "slbg2/slbg2 (3).jpg", "slbg2/slbg2 (4).jpg", "slbg2/slbg2 (5).jpg", "slbg2/slbg2 (6).jpg", "slbg2/slbg2 (7).jpg", "slbg2/slbg2 (8).jpg", "slbg2/slbg2 (9).jpg", "slbg2/slbg2 (10).jpg", "slbg2/slbg2 (11).jpg", "slbg2/slbg2 (12).jpg", "slbg2/slbg2 (13).jpg", "slbg2/slbg2 (14).jpg", "slbg2/slbg2 (15).jpg", "slbg2/slbg2 (16).jpg", "slbg2/slbg2 (17).jpg", "slbg2/slbg2 (18).jpg", "slbg2/slbg2 (19).jpg", "slbg2/slbg2 (20).jpg", "slbg2/slbg2 (21).jpg", "slbg2/slbg2 (22).jpg", "slbg2/slbg2 (23).jpg", "slbg2/slbg2 (24).jpg", "slbg2/slbg2 (25).jpg", "slbg2/slbg2 (26).jpg", "slbg2/slbg2 (27).jpg", "slbg2/slbg2 (28).jpg", "slbg2/slbg2 (29).jpg", "slbg2/slbg2 (30).jpg", "slbg2/slbg2 (31).jpg", "slbg2/slbg2 (32).jpg", "slbg2/slbg2 (33).jpg", "slbg2/slbg2 (34).jpg", "slbg2/slbg2 (35).jpg", "slbg2/slbg2 (36).jpg", "slbg2/slbg2 (37).jpg", "slbg2/slbg2 (38).jpg", "slbg2/slbg2 (39).jpg", "slbg2/slbg2 (40).jpg", "slbg2/slbg2 (41).jpg", "slbg2/slbg2 (42).jpg", "slbg2/slbg2 (43).jpg", "slbg2/slbg2 (44).jpg", "slbg2/slbg2 (45).jpg", "slbg2/slbg2 (46).jpg", "slbg2/slbg2 (47).jpg", "slbg2/slbg2 (48).jpg", "slbg2/slbg2 (49).jpg", "slbg2/slbg2 (50).jpg", "slbg2/slbg2 (51).jpg", "slbg2/slbg2 (52).jpg", "slbg2/slbg2 (53).jpg", "slbg2/slbg2 (54).jpg", "slbg2/slbg2 (55).jpg", "slbg2/slbg2 (56).jpg", "slbg2/slbg2 (57).jpg", "slbg2/slbg2 (58).jpg", "slbg2/slbg2 (59).jpg", "slbg2/slbg2 (60).jpg", "slbg2/slbg2 (61).jpg", "slbg2/slbg2 (62).jpg", "slbg2/slbg2 (63).jpg", "slbg2/slbg2 (64).jpg", "slbg2/slbg2 (65).jpg", "slbg2/slbg2 (66).jpg", "slbg2/slbg2 (67).jpg", "slbg2/slbg2 (68).jpg", "slbg2/slbg2 (69).jpg", "slbg2/slbg2 (70).jpg", "slbg2/slbg2 (71).jpg", "slbg2/slbg2 (72).jpg", "slbg2/slbg2 (73).jpg", "slbg2/slbg2 (74).jpg", "slbg2/slbg2 (75).jpg", "slbg2/slbg2 (76).jpg", "slbg2/slbg2 (77).jpg", "slbg2/slbg2 (78).jpg", "slbg2/slbg2 (79).jpg", "slbg2/slbg2 (80).jpg", "slbg2/slbg2 (81).jpg", "slbg2/slbg2 (82).jpg", "slbg2/slbg2 (83).jpg", "slbg2/slbg2 (84).jpg", "slbg2/slbg2 (85).jpg", "slbg2/slbg2 (86).jpg", "slbg2/slbg2 (87).jpg", "slbg2/slbg2 (88).jpg", "slbg2/slbg2 (89).jpg", "slbg2/slbg2 (90).jpg", "slbg2/slbg2 (91).jpg", "slbg2/slbg2 (92).jpg", "slbg2/slbg2 (93).jpg", "slbg2/slbg2 (94).jpg", "slbg2/slbg2 (95).jpg", "slbg2/slbg2 (96).jpg", "slbg2/slbg2 (97).jpg", "slbg2/slbg2 (98).jpg", "slbg2/slbg2 (99).jpg", "slbg2/slbg2 (100).jpg"};
char slbg3[100][30] = {"slbg3/slbg3 (1).jpg", "slbg3/slbg3 (2).jpg", "slbg3/slbg3 (3).jpg", "slbg3/slbg3 (4).jpg", "slbg3/slbg3 (5).jpg", "slbg3/slbg3 (6).jpg", "slbg3/slbg3 (7).jpg", "slbg3/slbg3 (8).jpg", "slbg3/slbg3 (9).jpg", "slbg3/slbg3 (10).jpg", "slbg3/slbg3 (11).jpg", "slbg3/slbg3 (12).jpg", "slbg3/slbg3 (13).jpg", "slbg3/slbg3 (14).jpg", "slbg3/slbg3 (15).jpg", "slbg3/slbg3 (16).jpg", "slbg3/slbg3 (17).jpg", "slbg3/slbg3 (18).jpg", "slbg3/slbg3 (19).jpg", "slbg3/slbg3 (20).jpg", "slbg3/slbg3 (21).jpg", "slbg3/slbg3 (22).jpg", "slbg3/slbg3 (23).jpg", "slbg3/slbg3 (24).jpg", "slbg3/slbg3 (25).jpg", "slbg3/slbg3 (26).jpg", "slbg3/slbg3 (27).jpg", "slbg3/slbg3 (28).jpg", "slbg3/slbg3 (29).jpg", "slbg3/slbg3 (30).jpg", "slbg3/slbg3 (31).jpg", "slbg3/slbg3 (32).jpg", "slbg3/slbg3 (33).jpg", "slbg3/slbg3 (34).jpg", "slbg3/slbg3 (35).jpg", "slbg3/slbg3 (36).jpg", "slbg3/slbg3 (37).jpg", "slbg3/slbg3 (38).jpg", "slbg3/slbg3 (39).jpg", "slbg3/slbg3 (40).jpg", "slbg3/slbg3 (41).jpg", "slbg3/slbg3 (42).jpg", "slbg3/slbg3 (43).jpg", "slbg3/slbg3 (44).jpg", "slbg3/slbg3 (45).jpg", "slbg3/slbg3 (46).jpg", "slbg3/slbg3 (47).jpg", "slbg3/slbg3 (48).jpg", "slbg3/slbg3 (49).jpg", "slbg3/slbg3 (50).jpg", "slbg3/slbg3 (51).jpg", "slbg3/slbg3 (52).jpg", "slbg3/slbg3 (53).jpg", "slbg3/slbg3 (54).jpg", "slbg3/slbg3 (55).jpg", "slbg3/slbg3 (56).jpg", "slbg3/slbg3 (57).jpg", "slbg3/slbg3 (58).jpg", "slbg3/slbg3 (59).jpg", "slbg3/slbg3 (60).jpg", "slbg3/slbg3 (61).jpg", "slbg3/slbg3 (62).jpg", "slbg3/slbg3 (63).jpg", "slbg3/slbg3 (64).jpg", "slbg3/slbg3 (65).jpg", "slbg3/slbg3 (66).jpg", "slbg3/slbg3 (67).jpg", "slbg3/slbg3 (68).jpg", "slbg3/slbg3 (69).jpg", "slbg3/slbg3 (70).jpg", "slbg3/slbg3 (71).jpg", "slbg3/slbg3 (72).jpg", "slbg3/slbg3 (73).jpg", "slbg3/slbg3 (74).jpg", "slbg3/slbg3 (75).jpg", "slbg3/slbg3 (76).jpg", "slbg3/slbg3 (77).jpg", "slbg3/slbg3 (78).jpg", "slbg3/slbg3 (79).jpg", "slbg3/slbg3 (80).jpg", "slbg3/slbg3 (81).jpg", "slbg3/slbg3 (82).jpg", "slbg3/slbg3 (83).jpg", "slbg3/slbg3 (84).jpg", "slbg3/slbg3 (85).jpg", "slbg3/slbg3 (86).jpg", "slbg3/slbg3 (87).jpg", "slbg3/slbg3 (88).jpg", "slbg3/slbg3 (89).jpg", "slbg3/slbg3 (90).jpg", "slbg3/slbg3 (91).jpg", "slbg3/slbg3 (92).jpg", "slbg3/slbg3 (93).jpg", "slbg3/slbg3 (94).jpg", "slbg3/slbg3 (95).jpg", "slbg3/slbg3 (96).jpg", "slbg3/slbg3 (97).jpg", "slbg3/slbg3 (98).jpg", "slbg3/slbg3 (99).jpg", "slbg3/slbg3 (100).jpg"};
char slbg4[100][30] = {"slbg4/slbg4 (1).jpg", "slbg4/slbg4 (2).jpg", "slbg4/slbg4 (3).jpg", "slbg4/slbg4 (4).jpg", "slbg4/slbg4 (5).jpg", "slbg4/slbg4 (6).jpg", "slbg4/slbg4 (7).jpg", "slbg4/slbg4 (8).jpg", "slbg4/slbg4 (9).jpg", "slbg4/slbg4 (10).jpg", "slbg4/slbg4 (11).jpg", "slbg4/slbg4 (12).jpg", "slbg4/slbg4 (13).jpg", "slbg4/slbg4 (14).jpg", "slbg4/slbg4 (15).jpg", "slbg4/slbg4 (16).jpg", "slbg4/slbg4 (17).jpg", "slbg4/slbg4 (18).jpg", "slbg4/slbg4 (19).jpg", "slbg4/slbg4 (20).jpg", "slbg4/slbg4 (21).jpg", "slbg4/slbg4 (22).jpg", "slbg4/slbg4 (23).jpg", "slbg4/slbg4 (24).jpg", "slbg4/slbg4 (25).jpg", "slbg4/slbg4 (26).jpg", "slbg4/slbg4 (27).jpg", "slbg4/slbg4 (28).jpg", "slbg4/slbg4 (29).jpg", "slbg4/slbg4 (30).jpg", "slbg4/slbg4 (31).jpg", "slbg4/slbg4 (32).jpg", "slbg4/slbg4 (33).jpg", "slbg4/slbg4 (34).jpg", "slbg4/slbg4 (35).jpg", "slbg4/slbg4 (36).jpg", "slbg4/slbg4 (37).jpg", "slbg4/slbg4 (38).jpg", "slbg4/slbg4 (39).jpg", "slbg4/slbg4 (40).jpg", "slbg4/slbg4 (41).jpg", "slbg4/slbg4 (42).jpg", "slbg4/slbg4 (43).jpg", "slbg4/slbg4 (44).jpg", "slbg4/slbg4 (45).jpg", "slbg4/slbg4 (46).jpg", "slbg4/slbg4 (47).jpg", "slbg4/slbg4 (48).jpg", "slbg4/slbg4 (49).jpg", "slbg4/slbg4 (50).jpg", "slbg4/slbg4 (51).jpg", "slbg4/slbg4 (52).jpg", "slbg4/slbg4 (53).jpg", "slbg4/slbg4 (54).jpg", "slbg4/slbg4 (55).jpg", "slbg4/slbg4 (56).jpg", "slbg4/slbg4 (57).jpg", "slbg4/slbg4 (58).jpg", "slbg4/slbg4 (59).jpg", "slbg4/slbg4 (60).jpg", "slbg4/slbg4 (61).jpg", "slbg4/slbg4 (62).jpg", "slbg4/slbg4 (63).jpg", "slbg4/slbg4 (64).jpg", "slbg4/slbg4 (65).jpg", "slbg4/slbg4 (66).jpg", "slbg4/slbg4 (67).jpg", "slbg4/slbg4 (68).jpg", "slbg4/slbg4 (69).jpg", "slbg4/slbg4 (70).jpg", "slbg4/slbg4 (71).jpg", "slbg4/slbg4 (72).jpg", "slbg4/slbg4 (73).jpg", "slbg4/slbg4 (74).jpg", "slbg4/slbg4 (75).jpg", "slbg4/slbg4 (76).jpg", "slbg4/slbg4 (77).jpg", "slbg4/slbg4 (78).jpg", "slbg4/slbg4 (79).jpg", "slbg4/slbg4 (80).jpg", "slbg4/slbg4 (81).jpg", "slbg4/slbg4 (82).jpg", "slbg4/slbg4 (83).jpg", "slbg4/slbg4 (84).jpg", "slbg4/slbg4 (85).jpg", "slbg4/slbg4 (86).jpg", "slbg4/slbg4 (87).jpg", "slbg4/slbg4 (88).jpg", "slbg4/slbg4 (89).jpg", "slbg4/slbg4 (90).jpg", "slbg4/slbg4 (91).jpg", "slbg4/slbg4 (92).jpg", "slbg4/slbg4 (93).jpg", "slbg4/slbg4 (94).jpg", "slbg4/slbg4 (95).jpg", "slbg4/slbg4 (96).jpg", "slbg4/slbg4 (97).jpg", "slbg4/slbg4 (98).jpg", "slbg4/slbg4 (99).jpg", "slbg4/slbg4 (100).jpg"};
char slbg5[100][30] = {"slbg5/slbg5 (1).jpg", "slbg5/slbg5 (2).jpg", "slbg5/slbg5 (3).jpg", "slbg5/slbg5 (4).jpg", "slbg5/slbg5 (5).jpg", "slbg5/slbg5 (6).jpg", "slbg5/slbg5 (7).jpg", "slbg5/slbg5 (8).jpg", "slbg5/slbg5 (9).jpg", "slbg5/slbg5 (10).jpg", "slbg5/slbg5 (11).jpg", "slbg5/slbg5 (12).jpg", "slbg5/slbg5 (13).jpg", "slbg5/slbg5 (14).jpg", "slbg5/slbg5 (15).jpg", "slbg5/slbg5 (16).jpg", "slbg5/slbg5 (17).jpg", "slbg5/slbg5 (18).jpg", "slbg5/slbg5 (19).jpg", "slbg5/slbg5 (20).jpg", "slbg5/slbg5 (21).jpg", "slbg5/slbg5 (22).jpg", "slbg5/slbg5 (23).jpg", "slbg5/slbg5 (24).jpg", "slbg5/slbg5 (25).jpg", "slbg5/slbg5 (26).jpg", "slbg5/slbg5 (27).jpg", "slbg5/slbg5 (28).jpg", "slbg5/slbg5 (29).jpg", "slbg5/slbg5 (30).jpg", "slbg5/slbg5 (31).jpg", "slbg5/slbg5 (32).jpg", "slbg5/slbg5 (33).jpg", "slbg5/slbg5 (34).jpg", "slbg5/slbg5 (35).jpg", "slbg5/slbg5 (36).jpg", "slbg5/slbg5 (37).jpg", "slbg5/slbg5 (38).jpg", "slbg5/slbg5 (39).jpg", "slbg5/slbg5 (40).jpg", "slbg5/slbg5 (41).jpg", "slbg5/slbg5 (42).jpg", "slbg5/slbg5 (43).jpg", "slbg5/slbg5 (44).jpg", "slbg5/slbg5 (45).jpg", "slbg5/slbg5 (46).jpg", "slbg5/slbg5 (47).jpg", "slbg5/slbg5 (48).jpg", "slbg5/slbg5 (49).jpg", "slbg5/slbg5 (50).jpg", "slbg5/slbg5 (51).jpg", "slbg5/slbg5 (52).jpg", "slbg5/slbg5 (53).jpg", "slbg5/slbg5 (54).jpg", "slbg5/slbg5 (55).jpg", "slbg5/slbg5 (56).jpg", "slbg5/slbg5 (57).jpg", "slbg5/slbg5 (58).jpg", "slbg5/slbg5 (59).jpg", "slbg5/slbg5 (60).jpg", "slbg5/slbg5 (61).jpg", "slbg5/slbg5 (62).jpg", "slbg5/slbg5 (63).jpg", "slbg5/slbg5 (64).jpg", "slbg5/slbg5 (65).jpg", "slbg5/slbg5 (66).jpg", "slbg5/slbg5 (67).jpg", "slbg5/slbg5 (68).jpg", "slbg5/slbg5 (69).jpg", "slbg5/slbg5 (70).jpg", "slbg5/slbg5 (71).jpg", "slbg5/slbg5 (72).jpg", "slbg5/slbg5 (73).jpg", "slbg5/slbg5 (74).jpg", "slbg5/slbg5 (75).jpg", "slbg5/slbg5 (76).jpg", "slbg5/slbg5 (77).jpg", "slbg5/slbg5 (78).jpg", "slbg5/slbg5 (79).jpg", "slbg5/slbg5 (80).jpg", "slbg5/slbg5 (81).jpg", "slbg5/slbg5 (82).jpg", "slbg5/slbg5 (83).jpg", "slbg5/slbg5 (84).jpg", "slbg5/slbg5 (85).jpg", "slbg5/slbg5 (86).jpg", "slbg5/slbg5 (87).jpg", "slbg5/slbg5 (88).jpg", "slbg5/slbg5 (89).jpg", "slbg5/slbg5 (90).jpg", "slbg5/slbg5 (91).jpg", "slbg5/slbg5 (92).jpg", "slbg5/slbg5 (93).jpg", "slbg5/slbg5 (94).jpg", "slbg5/slbg5 (95).jpg", "slbg5/slbg5 (96).jpg", "slbg5/slbg5 (97).jpg", "slbg5/slbg5 (98).jpg", "slbg5/slbg5 (99).jpg", "slbg5/slbg5 (100).jpg"};
char slbg6[100][30] = {"slbg6/slbg6 (1).jpg", "slbg6/slbg6 (2).jpg", "slbg6/slbg6 (3).jpg", "slbg6/slbg6 (4).jpg", "slbg6/slbg6 (5).jpg", "slbg6/slbg6 (6).jpg", "slbg6/slbg6 (7).jpg", "slbg6/slbg6 (8).jpg", "slbg6/slbg6 (9).jpg", "slbg6/slbg6 (10).jpg", "slbg6/slbg6 (11).jpg", "slbg6/slbg6 (12).jpg", "slbg6/slbg6 (13).jpg", "slbg6/slbg6 (14).jpg", "slbg6/slbg6 (15).jpg", "slbg6/slbg6 (16).jpg", "slbg6/slbg6 (17).jpg", "slbg6/slbg6 (18).jpg", "slbg6/slbg6 (19).jpg", "slbg6/slbg6 (20).jpg", "slbg6/slbg6 (21).jpg", "slbg6/slbg6 (22).jpg", "slbg6/slbg6 (23).jpg", "slbg6/slbg6 (24).jpg", "slbg6/slbg6 (25).jpg", "slbg6/slbg6 (26).jpg", "slbg6/slbg6 (27).jpg", "slbg6/slbg6 (28).jpg", "slbg6/slbg6 (29).jpg", "slbg6/slbg6 (30).jpg", "slbg6/slbg6 (31).jpg", "slbg6/slbg6 (32).jpg", "slbg6/slbg6 (33).jpg", "slbg6/slbg6 (34).jpg", "slbg6/slbg6 (35).jpg", "slbg6/slbg6 (36).jpg", "slbg6/slbg6 (37).jpg", "slbg6/slbg6 (38).jpg", "slbg6/slbg6 (39).jpg", "slbg6/slbg6 (40).jpg", "slbg6/slbg6 (41).jpg", "slbg6/slbg6 (42).jpg", "slbg6/slbg6 (43).jpg", "slbg6/slbg6 (44).jpg", "slbg6/slbg6 (45).jpg", "slbg6/slbg6 (46).jpg", "slbg6/slbg6 (47).jpg", "slbg6/slbg6 (48).jpg", "slbg6/slbg6 (49).jpg", "slbg6/slbg6 (50).jpg", "slbg6/slbg6 (51).jpg", "slbg6/slbg6 (52).jpg", "slbg6/slbg6 (53).jpg", "slbg6/slbg6 (54).jpg", "slbg6/slbg6 (55).jpg", "slbg6/slbg6 (56).jpg", "slbg6/slbg6 (57).jpg", "slbg6/slbg6 (58).jpg", "slbg6/slbg6 (59).jpg", "slbg6/slbg6 (60).jpg", "slbg6/slbg6 (61).jpg", "slbg6/slbg6 (62).jpg", "slbg6/slbg6 (63).jpg", "slbg6/slbg6 (64).jpg", "slbg6/slbg6 (65).jpg", "slbg6/slbg6 (66).jpg", "slbg6/slbg6 (67).jpg", "slbg6/slbg6 (68).jpg", "slbg6/slbg6 (69).jpg", "slbg6/slbg6 (70).jpg", "slbg6/slbg6 (71).jpg", "slbg6/slbg6 (72).jpg", "slbg6/slbg6 (73).jpg", "slbg6/slbg6 (74).jpg", "slbg6/slbg6 (75).jpg", "slbg6/slbg6 (76).jpg", "slbg6/slbg6 (77).jpg", "slbg6/slbg6 (78).jpg", "slbg6/slbg6 (79).jpg", "slbg6/slbg6 (80).jpg", "slbg6/slbg6 (81).jpg", "slbg6/slbg6 (82).jpg", "slbg6/slbg6 (83).jpg", "slbg6/slbg6 (84).jpg", "slbg6/slbg6 (85).jpg", "slbg6/slbg6 (86).jpg", "slbg6/slbg6 (87).jpg", "slbg6/slbg6 (88).jpg", "slbg6/slbg6 (89).jpg", "slbg6/slbg6 (90).jpg", "slbg6/slbg6 (91).jpg", "slbg6/slbg6 (92).jpg", "slbg6/slbg6 (93).jpg", "slbg6/slbg6 (94).jpg", "slbg6/slbg6 (95).jpg", "slbg6/slbg6 (96).jpg", "slbg6/slbg6 (97).jpg", "slbg6/slbg6 (98).jpg", "slbg6/slbg6 (99).jpg", "slbg6/slbg6 (100).jpg"};
char resume[250][30] = {"b/b (1).jpg", "b/b (2).jpg", "b/b (3).jpg", "b/b (4).jpg", "b/b (5).jpg", "b/b (6).jpg", "b/b (7).jpg", "b/b (8).jpg", "b/b (9).jpg", "b/b (10).jpg", "b/b (11).jpg", "b/b (12).jpg", "b/b (13).jpg", "b/b (14).jpg", "b/b (15).jpg", "b/b (16).jpg", "b/b (17).jpg", "b/b (18).jpg", "b/b (19).jpg", "b/b (20).jpg", "b/b (21).jpg", "b/b (22).jpg", "b/b (23).jpg", "b/b (24).jpg", "b/b (25).jpg", "b/b (26).jpg", "b/b (27).jpg", "b/b (28).jpg", "b/b (29).jpg", "b/b (30).jpg", "b/b (31).jpg", "b/b (32).jpg", "b/b (33).jpg", "b/b (34).jpg", "b/b (35).jpg", "b/b (36).jpg", "b/b (37).jpg", "b/b (38).jpg", "b/b (39).jpg", "b/b (40).jpg", "b/b (41).jpg", "b/b (42).jpg", "b/b (43).jpg", "b/b (44).jpg", "b/b (45).jpg", "b/b (46).jpg", "b/b (47).jpg", "b/b (48).jpg", "b/b (49).jpg", "b/b (50).jpg", "b/b (51).jpg", "b/b (52).jpg", "b/b (53).jpg", "b/b (54).jpg", "b/b (55).jpg", "b/b (56).jpg", "b/b (57).jpg", "b/b (58).jpg", "b/b (59).jpg", "b/b (60).jpg", "b/b (61).jpg", "b/b (62).jpg", "b/b (63).jpg", "b/b (64).jpg", "b/b (65).jpg", "b/b (66).jpg", "b/b (67).jpg", "b/b (68).jpg", "b/b (69).jpg", "b/b (70).jpg", "b/b (71).jpg", "b/b (72).jpg", "b/b (73).jpg", "b/b (74).jpg", "b/b (75).jpg", "b/b (76).jpg", "b/b (77).jpg", "b/b (78).jpg", "b/b (79).jpg", "b/b (80).jpg", "b/b (81).jpg", "b/b (82).jpg", "b/b (83).jpg", "b/b (84).jpg", "b/b (85).jpg", "b/b (86).jpg", "b/b (87).jpg", "b/b (88).jpg", "b/b (89).jpg", "b/b (90).jpg", "b/b (91).jpg", "b/b (92).jpg", "b/b (93).jpg", "b/b (94).jpg", "b/b (95).jpg", "b/b (96).jpg", "b/b (97).jpg", "b/b (98).jpg", "b/b (99).jpg", "b/b (100).jpg", "b/b (101).jpg", "b/b (102).jpg", "b/b (103).jpg", "b/b (104).jpg", "b/b (105).jpg", "b/b (106).jpg", "b/b (107).jpg", "b/b (108).jpg", "b/b (109).jpg", "b/b (110).jpg", "b/b (111).jpg", "b/b (112).jpg", "b/b (113).jpg", "b/b (114).jpg", "b/b (115).jpg", "b/b (116).jpg", "b/b (117).jpg", "b/b (118).jpg", "b/b (119).jpg", "b/b (120).jpg", "b/b (121).jpg", "b/b (122).jpg", "b/b (123).jpg", "b/b (124).jpg", "b/b (125).jpg", "b/b (126).jpg", "b/b (127).jpg", "b/b (128).jpg", "b/b (129).jpg", "b/b (130).jpg", "b/b (131).jpg", "b/b (132).jpg", "b/b (133).jpg", "b/b (134).jpg", "b/b (135).jpg", "b/b (136).jpg", "b/b (137).jpg", "b/b (138).jpg", "b/b (139).jpg", "b/b (140).jpg", "b/b (141).jpg", "b/b (142).jpg", "b/b (143).jpg", "b/b (144).jpg", "b/b (145).jpg", "b/b (146).jpg", "b/b (147).jpg", "b/b (148).jpg", "b/b (149).jpg", "b/b (150).jpg", "b/b (151).jpg", "b/b (152).jpg", "b/b (153).jpg", "b/b (154).jpg", "b/b (155).jpg", "b/b (156).jpg", "b/b (157).jpg", "b/b (158).jpg", "b/b (159).jpg", "b/b (160).jpg", "b/b (161).jpg", "b/b (162).jpg", "b/b (163).jpg", "b/b (164).jpg", "b/b (165).jpg", "b/b (166).jpg", "b/b (167).jpg", "b/b (168).jpg", "b/b (169).jpg", "b/b (170).jpg", "b/b (171).jpg", "b/b (172).jpg", "b/b (173).jpg", "b/b (174).jpg", "b/b (175).jpg", "b/b (176).jpg", "b/b (177).jpg", "b/b (178).jpg", "b/b (179).jpg", "b/b (180).jpg", "b/b (181).jpg", "b/b (182).jpg", "b/b (183).jpg", "b/b (184).jpg", "b/b (185).jpg", "b/b (186).jpg", "b/b (187).jpg", "b/b (188).jpg", "b/b (189).jpg", "b/b (190).jpg", "b/b (191).jpg", "b/b (192).jpg", "b/b (193).jpg", "b/b (194).jpg", "b/b (195).jpg", "b/b (196).jpg", "b/b (197).jpg", "b/b (198).jpg", "b/b (199).jpg", "b/b (200).jpg", "b/b (201).jpg", "b/b (202).jpg", "b/b (203).jpg", "b/b (204).jpg", "b/b (205).jpg", "b/b (206).jpg", "b/b (207).jpg", "b/b (208).jpg", "b/b (209).jpg", "b/b (210).jpg", "b/b (211).jpg", "b/b (212).jpg", "b/b (213).jpg", "b/b (214).jpg", "b/b (215).jpg", "b/b (216).jpg", "b/b (217).jpg", "b/b (218).jpg", "b/b (219).jpg", "b/b (220).jpg", "b/b (221).jpg", "b/b (222).jpg", "b/b (223).jpg", "b/b (224).jpg", "b/b (225).jpg", "b/b (226).jpg", "b/b (227).jpg", "b/b (228).jpg", "b/b (229).jpg", "b/b (230).jpg", "b/b (231).jpg", "b/b (232).jpg", "b/b (233).jpg", "b/b (234).jpg", "b/b (235).jpg", "b/b (236).jpg", "b/b (237).jpg", "b/b (238).jpg", "b/b (239).jpg", "b/b (240).jpg", "b/b (241).jpg", "b/b (242).jpg", "b/b (243).jpg", "b/b (244).jpg", "b/b (245).jpg", "b/b (246).jpg", "b/b (247).jpg", "b/b (248).jpg", "b/b (249).jpg", "b/b (250).jpg"};
char loadimage[200][30] = {"load/load (1).jpg", "load/load (2).jpg", "load/load (3).jpg", "load/load (4).jpg", "load/load (5).jpg", "load/load (6).jpg", "load/load (7).jpg", "load/load (8).jpg", "load/load (9).jpg", "load/load (10).jpg", "load/load (11).jpg", "load/load (12).jpg", "load/load (13).jpg", "load/load (14).jpg", "load/load (15).jpg", "load/load (16).jpg", "load/load (17).jpg", "load/load (18).jpg", "load/load (19).jpg", "load/load (20).jpg", "load/load (21).jpg", "load/load (22).jpg", "load/load (23).jpg", "load/load (24).jpg", "load/load (25).jpg", "load/load (26).jpg", "load/load (27).jpg", "load/load (28).jpg", "load/load (29).jpg", "load/load (30).jpg", "load/load (31).jpg", "load/load (32).jpg", "load/load (33).jpg", "load/load (34).jpg", "load/load (35).jpg", "load/load (36).jpg", "load/load (37).jpg", "load/load (38).jpg", "load/load (39).jpg", "load/load (40).jpg", "load/load (41).jpg", "load/load (42).jpg", "load/load (43).jpg", "load/load (44).jpg", "load/load (45).jpg", "load/load (46).jpg", "load/load (47).jpg", "load/load (48).jpg", "load/load (49).jpg", "load/load (50).jpg", "load/load (51).jpg", "load/load (52).jpg", "load/load (53).jpg", "load/load (54).jpg", "load/load (55).jpg", "load/load (56).jpg", "load/load (57).jpg", "load/load (58).jpg", "load/load (59).jpg", "load/load (60).jpg", "load/load (61).jpg", "load/load (62).jpg", "load/load (63).jpg", "load/load (64).jpg", "load/load (65).jpg", "load/load (66).jpg", "load/load (67).jpg", "load/load (68).jpg", "load/load (69).jpg", "load/load (70).jpg", "load/load (71).jpg", "load/load (72).jpg", "load/load (73).jpg", "load/load (74).jpg", "load/load (75).jpg", "load/load (76).jpg", "load/load (77).jpg", "load/load (78).jpg", "load/load (79).jpg", "load/load (80).jpg", "load/load (81).jpg", "load/load (82).jpg", "load/load (83).jpg", "load/load (84).jpg", "load/load (85).jpg", "load/load (86).jpg", "load/load (87).jpg", "load/load (88).jpg", "load/load (89).jpg", "load/load (90).jpg", "load/load (91).jpg", "load/load (92).jpg", "load/load (93).jpg", "load/load (94).jpg", "load/load (95).jpg", "load/load (96).jpg", "load/load (97).jpg", "load/load (98).jpg", "load/load (99).jpg", "load/load (100).jpg", "load/load (101).jpg", "load/load (102).jpg", "load/load (103).jpg", "load/load (104).jpg", "load/load (105).jpg", "load/load (106).jpg", "load/load (107).jpg", "load/load (108).jpg", "load/load (109).jpg", "load/load (110).jpg", "load/load (111).jpg", "load/load (112).jpg", "load/load (113).jpg", "load/load (114).jpg", "load/load (115).jpg", "load/load (116).jpg", "load/load (117).jpg", "load/load (118).jpg", "load/load (119).jpg", "load/load (120).jpg", "load/load (121).jpg", "load/load (122).jpg", "load/load (123).jpg", "load/load (124).jpg", "load/load (125).jpg", "load/load (126).jpg", "load/load (127).jpg", "load/load (128).jpg", "load/load (129).jpg", "load/load (130).jpg", "load/load (131).jpg", "load/load (132).jpg", "load/load (133).jpg", "load/load (134).jpg", "load/load (135).jpg", "load/load (136).jpg", "load/load (137).jpg", "load/load (138).jpg", "load/load (139).jpg", "load/load (140).jpg", "load/load (141).jpg", "load/load (142).jpg", "load/load (143).jpg", "load/load (144).jpg", "load/load (145).jpg", "load/load (146).jpg", "load/load (147).jpg", "load/load (148).jpg", "load/load (149).jpg", "load/load (150).jpg", "load/load (151).jpg", "load/load (152).jpg", "load/load (153).jpg", "load/load (154).jpg", "load/load (155).jpg", "load/load (156).jpg", "load/load (157).jpg", "load/load (158).jpg", "load/load (159).jpg", "load/load (160).jpg", "load/load (161).jpg", "load/load (162).jpg", "load/load (163).jpg", "load/load (164).jpg", "load/load (165).jpg", "load/load (166).jpg", "load/load (167).jpg", "load/load (168).jpg", "load/load (169).jpg", "load/load (170).jpg", "load/load (171).jpg", "load/load (172).jpg", "load/load (173).jpg", "load/load (174).jpg", "load/load (175).jpg", "load/load (176).jpg", "load/load (177).jpg", "load/load (178).jpg", "load/load (179).jpg", "load/load (180).jpg", "load/load (181).jpg", "load/load (182).jpg", "load/load (183).jpg", "load/load (184).jpg", "load/load (185).jpg", "load/load (186).jpg", "load/load (187).jpg", "load/load (188).jpg", "load/load (189).jpg", "load/load (190).jpg", "load/load (191).jpg", "load/load (192).jpg", "load/load (193).jpg", "load/load (194).jpg", "load/load (195).jpg", "load/load (196).jpg", "load/load (197).jpg", "load/load (198).jpg", "load/load (199).jpg", "load/load (200).jpg"};
char scoreshowimage[100][50] = {"congrats/congrats (1).jpg", "congrats/congrats (2).jpg", "congrats/congrats (3).jpg", "congrats/congrats (4).jpg", "congrats/congrats (5).jpg", "congrats/congrats (6).jpg", "congrats/congrats (7).jpg", "congrats/congrats (8).jpg", "congrats/congrats (9).jpg", "congrats/congrats (10).jpg", "congrats/congrats (11).jpg", "congrats/congrats (12).jpg", "congrats/congrats (13).jpg", "congrats/congrats (14).jpg", "congrats/congrats (15).jpg", "congrats/congrats (16).jpg", "congrats/congrats (17).jpg", "congrats/congrats (18).jpg", "congrats/congrats (20).jpg", "congrats/congrats (20).jpg", "congrats/congrats (21).jpg", "congrats/congrats (22).jpg", "congrats/congrats (23).jpg", "congrats/congrats (24).jpg", "congrats/congrats (25).jpg", "congrats/congrats (26).jpg", "congrats/congrats (27).jpg", "congrats/congrats (28).jpg", "congrats/congrats (29).jpg", "congrats/congrats (30).jpg", "congrats/congrats (31).jpg", "congrats/congrats (32).jpg", "congrats/congrats (33).jpg", "congrats/congrats (34).jpg", "congrats/congrats (35).jpg", "congrats/congrats (36).jpg", "congrats/congrats (37).jpg", "congrats/congrats (38).jpg", "congrats/congrats (39).jpg", "congrats/congrats (40).jpg", "congrats/congrats (41).jpg", "congrats/congrats (42).jpg", "congrats/congrats (43).jpg", "congrats/congrats (44).jpg", "congrats/congrats (45).jpg", "congrats/congrats (46).jpg", "congrats/congrats (47).jpg", "congrats/congrats (48).jpg", "congrats/congrats (49).jpg", "congrats/congrats (50).jpg", "congrats/congrats (51).jpg", "congrats/congrats (52).jpg", "congrats/congrats (53).jpg", "congrats/congrats (54).jpg", "congrats/congrats (55).jpg", "congrats/congrats (56).jpg", "congrats/congrats (57).jpg", "congrats/congrats (58).jpg", "congrats/congrats (59).jpg", "congrats/congrats (60).jpg", "congrats/congrats (61).jpg", "congrats/congrats (62).jpg", "congrats/congrats (63).jpg", "congrats/congrats (64).jpg", "congrats/congrats (65).jpg", "congrats/congrats (66).jpg", "congrats/congrats (67).jpg", "congrats/congrats (68).jpg", "congrats/congrats (69).jpg", "congrats/congrats (70).jpg", "congrats/congrats (71).jpg", "congrats/congrats (72).jpg", "congrats/congrats (73).jpg", "congrats/congrats (74).jpg", "congrats/congrats (75).jpg", "congrats/congrats (76).jpg", "congrats/congrats (77).jpg", "congrats/congrats (78).jpg", "congrats/congrats (79).jpg", "congrats/congrats (80).jpg", "congrats/congrats (81).jpg", "congrats/congrats (82).jpg", "congrats/congrats (83).jpg", "congrats/congrats (84).jpg", "congrats/congrats (85).jpg", "congrats/congrats (86).jpg", "congrats/congrats (87).jpg", "congrats/congrats (88).jpg", "congrats/congrats (89).jpg", "congrats/congrats (90).jpg", "congrats/congrats (91).jpg", "congrats/congrats (92).jpg", "congrats/congrats (93).jpg", "congrats/congrats (94).jpg", "congrats/congrats (95).jpg", "congrats/congrats (96).jpg", "congrats/congrats (97).jpg", "congrats/congrats (98).jpg", "congrats/congrats (99).jpg", "congrats/congrats (100).jpg"};
char life[9][50] = {"life/love (3).png", "life/love (2).png", "life/love (1).png", "life/love10.png", "life/love12.png", "life/love1.png", "life/love6.png", "life/love8.png", "life/love14.png"};

char pacmanRight[2][30] = {"pacman/pacman (1).png", "pacman/pacman (2).png"};
char pacmanLeft[2][30] = {"pacman/pacman (5).png", "pacman/pacman (6).png"};
char pacmanUp[2][30] = {"pacman/pacman (7).png", "pacman/pacman (8).png"};
char pacmanDown[2][30] = {"pacman/pacman (3).png", "pacman/pacman (4).png"};
char pacdeadscene[11][30] = {"death/Death0.png", "death/Death1.png", "death/Death2.png", "death/Death3.png", "death/Death4.png", "death/Death5.png", "death/Death6.png", "death/Death7.png", "death/Death8.png", "death/Death9.png", "death/Death10.png"};
char fruit[16][30] = {"fruit/fruit (1).png", "fruit/fruit (2).png", "fruit/fruit (3).png", "fruit/fruit (4).png", "fruit/fruit (5).png", "fruit/fruit (6).png", "fruit/fruit (7).png", "fruit/fruit (8).png", "fruit/fruit (9).png", "fruit/fruit (10).png", "fruit/fruit (11).png", "fruit/fruit (12).png", "fruit/fruit (13).png", "fruit/fruit (14).png", "fruit/fruit (15).png", "fruit/fruit (16).png"};

char inkyUp[2][30] = {"inky/inky (2).png", "inky/inky (3).png"};
char inkyLeft[2][30] = {"inky/inky (7).png", "inky/inky (8).png"};
char inkyDown[2][30] = {"inky/inky (5).png", "inky/inky (6).png"};
char inkyRight[2][30] = {"inky/inky (1).png", "inky/inky (4).png"};

char blinkyUp[2][30] = {"blinky/blinky (2).png", "blinky/blinky (3).png"};
char blinkyDown[2][30] = {"blinky/blinky (5).png", "blinky/blinky (6).png"};
char blinkyRight[2][30] = {"blinky/blinky (1).png", "blinky/blinky (4).png"};
char blinkyLeft[2][30] = {"blinky/blinky (7).png", "blinky/blinky (8).png"};

char pinkyUp[2][30] = {"pinky/pinky (2).png", "pinky/pinky (3).png"};
char pinkyDown[2][30] = {"pinky/pinky (5).png", "pinky/pinky (6).png"};
char pinkyLeft[2][30] = {"pinky/pinky (7).png", "pinky/pinky (8).png"};
char pinkyRight[2][30] = {"pinky/pinky (1).png", "pinky/pinky (4).png"};

char clydeUp[2][30] = {"clyde/clyde (1).png", "clyde/clyde (2).png"};
char clydeDown[2][30] = {"clyde/clyde (5).png", "clyde/clyde (6).png"};
char clydeLeft[2][30] = {"clyde/clyde (7).png", "clyde/clyde (8).png"};
char clydeRight[2][30] = {"clyde/clyde (3).png", "clyde/clyde (4).png"};

char rinkyUp[2][30] = {"rinky/rinky7.png", "rinky/rinky8.png"};
char rinkyDown[2][30] = {"rinky/rinky3.png", "rinky/rinky4.png"};
char rinkyLeft[2][30] = {"rinky/rinky5.png", "rinky/rinky6.png"};
char rinkyRight[2][30] = {"rinky/rinky1.png", "rinky/rinky2.png"};

char donkyUp[2][30] = {"donky/donky7.png", "donky/donky8.png"};
char donkyDown[2][30] = {"donky/donky3.png", "donky/donky4.png"};
char donkyRight[2][30] = {"donky/donky1.png", "donky/donky2.png"};
char donkyLeft[2][30] = {"donky/donky5.png", "donky/donky6.png"};

char frozenGhost[2][40] = {"frozen/frozen (1).png", "frozen/frozen (2).png"};
char frozenGhostEnd[2][40] = {"frozen/frozen (2).png", "frozen/frozen (3).png"};

int maze1[21][21] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void corrdinatestore1()
{
    int i, j;
    int dx = startX12, dy = startY12;
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 21; j++)
        {
            map1CoordinateX[i][j] = dx;
            map1CoordinateY[i][j] = dy;
            dx += mazeCellWidth;
        }
        dx = startX12;
        dy -= mazeCellWidth;
    }
}
int maze2[21][21] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
void corrdinatestore2()
{
    int i, j;
    int dx = startX12, dy = startY12;
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 21; j++)
        {
            map2CoordinateX[i][j] = dx;
            map2CoordinateY[i][j] = dy;
            dx += mazeCellWidth;
        }
        dx = startX12;
        dy -= mazeCellWidth;
    }
}
int maze3[19][36] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
void corrdinatestore3()
{
    int i, j;
    int dx = startx3, dy = starty3;
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 36; j++)
        {
            map3CoordinateX[i][j] = dx;
            map3CoordinateY[i][j] = dy;
            dx += mazeCellWidth;
        }
        dx = startx3;
        dy -= mazeCellWidth;
    }
}

int maze4[21][40] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
void corrdinatestore4()
{
    int i, j;
    int dx = startx4, dy = starty4;
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 40; j++)
        {
            map4CoordinateX[i][j] = dx;
            map4CoordinateY[i][j] = dy;
            dx += mazeCellWidth;
        }
        dx = startx4;
        dy -= mazeCellWidth;
    }
}

void drawMaze1()
{
    int i, j;
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 21; j++)
        {
            if (maze1[i][j] == 1)
            {
                iShowImage(map1CoordinateX[i][j], map1CoordinateY[i][j], mazeimage[maze]);
            }
        }
    }
}
void drawMaze2()
{
    int i, j;
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 21; j++)
        {
            if (maze2[i][j] == 1)
            {
                iShowImage(map2CoordinateX[i][j], map2CoordinateY[i][j], mazeimage[maze]);
            }
        }
    }
}
void drawMaze3()
{
    int i, j;
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 36; j++)
        {
            if (maze3[i][j] == 1)
            {
                iShowImage(map3CoordinateX[i][j], map3CoordinateY[i][j], mazeimage[maze]);
            }
        }
    }
}
void drawMaze4()
{
    int i, j;
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 40; j++)
        {
            if (maze4[i][j] == 1)
            {
                iShowImage(map4CoordinateX[i][j], map4CoordinateY[i][j], mazeimage[maze]);
            }
        }
    }
}
// Function to replace underscores with spaces
void replaceUnderscoreWithSpace()
{
    for (int i = 0; i < line; i++)
    {
        // Go through each character in the name
        for (int j = 0; name[i][j] != '\0'; j++)
        {
            // If underscore found, replace with space
            if (name[i][j] == '_')
            {
                name[i][j] = ' ';
            }
        }
    }
    // Now name[i] array has spaces instead of underscores
}
void drawFoodAndPowerPellet()
{
    for (int i = 0; i < foodNum; i++)
    {
        int x = foodXcor[i][0];
        int y = foodYcor[i];

        if (foodXcor[i][1] == -1)
            continue; // Skip eaten food

        // Draw fruit (bonus item)
        if (foodXcor[i][1] == -2)
        {
            iShowImage(x, y, fruit[randGen]);
            continue;
        }

        //  Draw power pellets by maze level
        int isPowerPellet = 0;

        if (selected == 1 && (i == 0 || i == 18 || i == 149 || i == 104))
            isPowerPellet = 1;
        else if (selected == 2 && (i == 0 || i == 18 || i == 165 || i == 156))
            isPowerPellet = 1;
        else if (selected == 3 && (i == 84 || i == 292 || i == 100 || i == 200))
            isPowerPellet = 1;
        else if (selected == 4 && (i == 318 || i == 37 || i == 87 || i == 163 || i == 172 || i == 244 || i == 261 || i == 335 || i == 453 || i == 472))
            isPowerPellet = 1;

        if (isPowerPellet)
        {
            iSetColor(50, 205, 50); //  Sky blue
            iFilledCircle(x + 12, y + 12, 4.5);
            iSetColor(255, 140, 0); // Reset to yellow or any dot color
        }
        else
        {
            // Regular
            iSetColor(255, 140, 0); // Your default yellow dot color
            iFilledCircle(x + 12, y + 12, 3);
        }
    }
}
void foodcount()
{
    if (selected == 1)
    {
        totalfood = 226;
    }
    else if (selected == 2)
    {
        totalfood = 241;
    }
    else if (selected == 3)
    {
        totalfood = 367;
    }
    else if (selected == 4)
    {
        totalfood = 482;
    }
}

char *converter(int num, char *str)
{
    if (str == NULL)
    {
        return NULL;
    }
    sprintf(str, "%d", num);
    return str;
}
void storeGameStat()
{

    FILE *input = fopen("gamestat.txt", "w");
    if (input == NULL)
    {
        printf("Error saving game state!\n");
        return;
    }
    fprintf(input, "%s\n", playername);
    fprintf(input, "%d\n", selected);
    fprintf(input, "%d %d %d %d\n", pac.x, pac.y, cellX, cellY);
    fprintf(input, "%d %d %d %d\n", pac.rightCount, pac.leftCount, pac.upCount, pac.downCount);
    fprintf(input, "%d %d %d %d\n", pac.rightInd, pac.leftInd, pac.upInd, pac.downInd);
    fprintf(input, "%d %d\n", pac.right, pac.left); // movement timing
    fprintf(input, "%d %d\n", pac.up, pac.down);
    fprintf(input, "%d %d %d %d\n", pac.smoothRight, pac.smoothLeft, pac.smoothUp, pac.smoothDown);
    if (selected == 3 || selected == 4)
    {
        for (int i = 0; i < 6; i++)
        {
            fprintf(input, "%d %d %d %d %d\n", pookie[i].x, pookie[i].y, pookie[i].cellX, pookie[i].cellY, pookie[i].speed);
            fprintf(input, "%d %d %d %d\n", pookie[i].flagRight, pookie[i].flagLeft, pookie[i].flagUp, pookie[i].flagDown);
            fprintf(input, "%d %d %d %d\n", pookie[i].rightInd, pookie[i].leftInd, pookie[i].upInd, pookie[i].downInd);
            fprintf(input, "%d\n", pookie[i].blueOn); // optional
        }
    }
    if (selected == 1 || selected == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            fprintf(input, "%d %d %d %d %d\n", pookie[i].x, pookie[i].y, pookie[i].cellX, pookie[i].cellY, pookie[i].speed);
            fprintf(input, "%d %d %d %d\n", pookie[i].flagRight, pookie[i].flagLeft, pookie[i].flagUp, pookie[i].flagDown);
            fprintf(input, "%d %d %d %d\n", pookie[i].rightInd, pookie[i].leftInd, pookie[i].upInd, pookie[i].downInd);
            fprintf(input, "%d\n", pookie[i].blueOn); // optional
        }
    }
    fprintf(input, "%d %d\n", deadscene, deadSceneCount);
    fprintf(input, "%d\n", soundOn);
    fprintf(input, "%d %d %d %d\n", mazeWidth, mazeHeight, mazeCellWidth, mazeCellHeight);

    fprintf(input, "%d\n", foodNum);
    for (int i = 0; i < foodNum; i++)
    {
        fprintf(input, "%d %d %d\n", foodXcor[i][0], foodYcor[i], foodXcor[i][1]); // includes fruit/pellet states
    }
    fprintf(input, "%d\n", totalfood);

    fprintf(input, "%d %d\n", randGen, t);
    for (int i = 0; i < t; i++)
    {
        fprintf(input, "%d\n", fruitGen[i]);
    }
    fprintf(input, "%d %s\n", score, pacScore);
    fprintf(input, "%d\n", pacmanlife);
    fprintf(input, "%d %d %d\n", scatter, chase, blast);
    fprintf(input, "%d\n", diffSpeed);
    fprintf(input, "%d %d\n", blueGhost, blueScore);
    fprintf(input, "%d %d %d\n", bgimage, slbgimage, backgroundselectorc);
    fprintf(input, "%d %d\n", settingsc, difficultyc);
    fprintf(input, "%d %d\n", maze, mazeX);       // if needed
    fprintf(input, "%d %d\n", mazeY, mazeHeight); // if needed
    fprintf(input, "%d\n", mazeselectorc);

    fclose(input);
}
void loadGameStat()
{
    FILE *input = fopen("gamestat.txt", "r");
    if (input == NULL)
    {
        printf("Error loading game state!\n");
        return;
    }

    fscanf(input, "%s", playername);
    fscanf(input, "%d", &selected);
    fscanf(input, "%d %d %d %d", &pac.x, &pac.y, &cellX, &cellY);
    fscanf(input, "%d %d %d %d", &pac.rightCount, &pac.leftCount, &pac.upCount, &pac.downCount);
    fscanf(input, "%d %d %d %d", &pac.rightInd, &pac.leftInd, &pac.upInd, &pac.downInd);
    fscanf(input, "%d %d", &pac.right, &pac.left);
    fscanf(input, "%d %d", &pac.up, &pac.down);
    fscanf(input, "%d %d %d %d", &pac.smoothRight, &pac.smoothLeft, &pac.smoothUp, &pac.smoothDown);

    if (selected == 3 || selected == 4)
    {
        for (int i = 0; i < 6; i++)
        {
            fscanf(input, "%d %d %d %d %d", &pookie[i].x, &pookie[i].y, &pookie[i].cellX, &pookie[i].cellY, &pookie[i].speed);
            fscanf(input, "%d %d %d %d", &pookie[i].flagRight, &pookie[i].flagLeft, &pookie[i].flagUp, &pookie[i].flagDown);
            fscanf(input, "%d %d %d %d", &pookie[i].rightInd, &pookie[i].leftInd, &pookie[i].upInd, &pookie[i].downInd);
            fscanf(input, "%d", &pookie[i].blueOn);
        }
    }
    if (selected == 1 || selected == 2)
    {
        for (int i = 0; i < 4; i++)
        {
            fscanf(input, "%d %d %d %d %d", &pookie[i].x, &pookie[i].y, &pookie[i].cellX, &pookie[i].cellY, &pookie[i].speed);
            fscanf(input, "%d %d %d %d", &pookie[i].flagRight, &pookie[i].flagLeft, &pookie[i].flagUp, &pookie[i].flagDown);
            fscanf(input, "%d %d %d %d", &pookie[i].rightInd, &pookie[i].leftInd, &pookie[i].upInd, &pookie[i].downInd);
            fscanf(input, "%d", &pookie[i].blueOn);
        }
    }

    fscanf(input, "%d %d", &deadscene, &deadSceneCount);
    fscanf(input, "%d", &soundOn);
    fscanf(input, "%d %d %d %d", &mazeWidth, &mazeHeight, &mazeCellWidth, &mazeCellHeight);

    fscanf(input, "%d", &foodNum);
    for (int i = 0; i < foodNum; i++)
    {
        fscanf(input, "%d %d %d", &foodXcor[i][0], &foodYcor[i], &foodXcor[i][1]);
    }
    fscanf(input, "%d", &totalfood);

    fscanf(input, "%d %d", &randGen, &t);
    for (int i = 0; i < t; i++)
    {
        fscanf(input, "%d", &fruitGen[i]);
    }
    fscanf(input, "%d %s", &score, pacScore);
    fscanf(input, "%d", &pacmanlife);
    fscanf(input, "%d %d %d", &scatter, &chase, &blast);
    fscanf(input, "%d", &diffSpeed);
    fscanf(input, "%d %d", &blueGhost, &blueScore);
    fscanf(input, "%d %d %d", &bgimage, &slbgimage, &backgroundselectorc);
    fscanf(input, "%d %d", &settingsc, &difficultyc);
    fscanf(input, "%d %d", &maze, &mazeX);
    fscanf(input, "%d %d", &mazeY, &mazeHeight);
    fscanf(input, "%d", &mazeselectorc);

    fclose(input);
}

/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
    iClear();
    if (startintro)
    {
        iShowImage(0, 0, introimage[intro]);
    }
    else if (mainmenu)
    {
        iShowImage(0, 0, menuimage[menuc]);
    }
    if (resumeimage)
    {
        iShowImage(73, 485, resume[resumec]);
    }
    else if (difficulty)
    {
        iShowImage(0, 0, difficultyimage[difficultyc]);
        iShowText(45, 28, "BACK", "text.ttf", 50);
    }
    else if (highscore)
    {
        iShowImage(0, 0, highscoreimage[highscorec]);

        for (int i = 0; i < line; i++)
        {
            replaceUnderscoreWithSpace();
            if (i > 4)
            {
                break;
            }
            if (i == 0)
                iSetColor(255, 215, 0);
            else if (i == 1)
                iSetColor(169, 169, 169);
            else if (i == 2)
                iSetColor(205, 127, 50);
            else
                iSetColor(0, 0, 0);

            iShowText(186, 391 - (i * 88), name[i], "text.ttf", 40);
            iShowText(810, 391 - (i * 88), converter(point[i], temp), "text.ttf", 40);
            // iShowText(double x, double y, const char *text, const char *fontPath, int fontSize = 48)
        }
    }
    else if (load)
    {
        iShowImage(0, 0, loadimage[loadc]);
    }
    else if (playgameintro)
    {
        iShowImage(0, 0, playgameintroimage[0]);
        iSetColor(255, 255, 255);
        iShowText(430, 282, namestr, "text.ttf", 40);
    }
    else if (settings)
    {
        iShowImage(0, 0, settingsimage[settingsc]);
    }
    else if (mazeselector)
    {
        iShowImage(0, 0, mazeselectorimage[mazeselectorc]);
        iSetColor(0, 0, 0);
        iShowText(40, 35, "Back", "text.ttf", 50);
    }
    else if (credits)
    {
        iShowImage(0, 0, creditimage[creditsc]);
    }
    else if (rules)
    {
        iShowImage(0, 0, rulesimage[rulescene]);
    }
    else if (quit)
    {
        iShowImage(0, 0, quitimage[quitc]);
    }
    else if (specialthanks)
    {
        iShowImage(0, 0, "specialThanks.png");
    }
    else if (playingstart)
    {
        iShowImage(0, 0, backgroundimage[bgimage]);
        drawFoodAndPowerPellet();
        iSetColor(255, 255, 255);
        iShowText(1056, 625, pacScore, "text.ttf", 30);
        iShowText(950, 625, "Score:", "text.ttf", 45);
        iShowText(950, 567, "Life:", "text.ttf", 45);
        //  iText(1056, 625, pacScore, GLUT_BITMAP_TIMES_ROMAN_24);
        for (int i = 0; i < pacmanlife; i++)
        {
            if (i > 3)
            {
                iShowImage(1040 + 40 * (i - 4), 537, life[i]);
            }
            else
            {
                iShowImage(1040 + 40 * i, 567, life[i]);
            }
        }
        if (selected == 1)
        {
            drawMaze1();
        }
        else if (selected == 2)
        {
            drawMaze2();
        }
        else if (selected == 3)
        {
            drawMaze3();
        }
        else if (selected == 4)
        {
            drawMaze4();
        }

        if (!pacdead && pacmanlife)
        {
            if (pac.rightCount)
                iShowImage(pac.x, pac.y, pacmanRight[pac.rightInd]);
            else if (pac.leftCount)
                iShowImage(pac.x, pac.y, pacmanLeft[pac.leftInd]);
            else if (pac.upCount)
                iShowImage(pac.x, pac.y, pacmanUp[pac.upInd]);
            else if (pac.downCount)
                iShowImage(pac.x, pac.y, pacmanDown[pac.downInd]);
            else
                iShowImage(pac.x, pac.y, pacmanRight[pac.rightInd]);
        }
        else if (pacdead)
        {
            iShowImage(pac.x, pac.y, pacdeadscene[deadSceneCount]);
        }
        else
        {
            playingstart = 0;
            congrats = 1;
            storeGameStat();
        }

        if (!blueGhost)
        {
            if (selected == 1 || selected == 2)
            {
                if (pookie[0].flagRight)
                    iShowImage(pookie[0].x, pookie[0].y, inkyRight[pookie[0].rightInd]);
                else if (pookie[0].flagLeft)
                    iShowImage(pookie[0].x, pookie[0].y, inkyLeft[pookie[0].leftInd]);
                else if (pookie[0].flagUp)
                    iShowImage(pookie[0].x, pookie[0].y, inkyUp[pookie[0].upInd]);
                else if (pookie[0].flagDown)
                    iShowImage(pookie[0].x, pookie[0].y, inkyDown[pookie[0].downInd]);

                if (pookie[1].flagRight)
                    iShowImage(pookie[1].x, pookie[1].y, blinkyRight[pookie[1].rightInd]);
                else if (pookie[1].flagLeft)
                    iShowImage(pookie[1].x, pookie[1].y, blinkyLeft[pookie[1].leftInd]);
                else if (pookie[1].flagUp)
                    iShowImage(pookie[1].x, pookie[1].y, blinkyUp[pookie[1].upInd]);
                else if (pookie[1].flagDown)
                    iShowImage(pookie[1].x, pookie[1].y, blinkyDown[pookie[1].downInd]);

                if (pookie[2].flagRight)
                    iShowImage(pookie[2].x, pookie[2].y, clydeRight[pookie[2].rightInd]);
                else if (pookie[2].flagLeft)
                    iShowImage(pookie[2].x, pookie[2].y, clydeLeft[pookie[2].leftInd]);
                else if (pookie[2].flagUp)
                    iShowImage(pookie[2].x, pookie[2].y, clydeUp[pookie[2].upInd]);
                else if (pookie[2].flagDown)
                    iShowImage(pookie[2].x, pookie[2].y, clydeDown[pookie[2].downInd]);

                if (pookie[3].flagRight)
                    iShowImage(pookie[3].x, pookie[3].y, pinkyRight[pookie[3].rightInd]);
                else if (pookie[3].flagLeft)
                    iShowImage(pookie[3].x, pookie[3].y, pinkyLeft[pookie[3].leftInd]);
                else if (pookie[3].flagUp)
                    iShowImage(pookie[3].x, pookie[3].y, pinkyUp[pookie[3].upInd]);
                else if (pookie[3].flagDown)
                    iShowImage(pookie[3].x, pookie[3].y, pinkyDown[pookie[3].downInd]);
            }
            if (selected == 3 || selected == 4)
            {
                if (pookie[0].flagRight)
                    iShowImage(pookie[0].x, pookie[0].y, inkyRight[pookie[0].rightInd]);
                else if (pookie[0].flagLeft)
                    iShowImage(pookie[0].x, pookie[0].y, inkyLeft[pookie[0].leftInd]);
                else if (pookie[0].flagUp)
                    iShowImage(pookie[0].x, pookie[0].y, inkyUp[pookie[0].upInd]);
                else if (pookie[0].flagDown)
                    iShowImage(pookie[0].x, pookie[0].y, inkyDown[pookie[0].downInd]);

                if (pookie[1].flagRight)
                    iShowImage(pookie[1].x, pookie[1].y, blinkyRight[pookie[1].rightInd]);
                else if (pookie[1].flagLeft)
                    iShowImage(pookie[1].x, pookie[1].y, blinkyLeft[pookie[1].leftInd]);
                else if (pookie[1].flagUp)
                    iShowImage(pookie[1].x, pookie[1].y, blinkyUp[pookie[1].upInd]);
                else if (pookie[1].flagDown)
                    iShowImage(pookie[1].x, pookie[1].y, blinkyDown[pookie[1].downInd]);

                if (pookie[2].flagRight)
                    iShowImage(pookie[2].x, pookie[2].y, clydeRight[pookie[2].rightInd]);
                else if (pookie[2].flagLeft)
                    iShowImage(pookie[2].x, pookie[2].y, clydeLeft[pookie[2].leftInd]);
                else if (pookie[2].flagUp)
                    iShowImage(pookie[2].x, pookie[2].y, clydeUp[pookie[2].upInd]);
                else if (pookie[2].flagDown)
                    iShowImage(pookie[2].x, pookie[2].y, clydeDown[pookie[2].downInd]);

                if (pookie[3].flagRight)
                    iShowImage(pookie[3].x, pookie[3].y, pinkyRight[pookie[3].rightInd]);
                else if (pookie[3].flagLeft)
                    iShowImage(pookie[3].x, pookie[3].y, pinkyLeft[pookie[3].leftInd]);
                else if (pookie[3].flagUp)
                    iShowImage(pookie[3].x, pookie[3].y, pinkyUp[pookie[3].upInd]);
                else if (pookie[3].flagDown)
                    iShowImage(pookie[3].x, pookie[3].y, pinkyDown[pookie[3].downInd]);

                if (pookie[4].flagRight)
                    iShowImage(pookie[4].x, pookie[4].y, donkyRight[pookie[4].rightInd]);
                else if (pookie[4].flagLeft)
                    iShowImage(pookie[4].x, pookie[4].y, donkyLeft[pookie[4].leftInd]);
                else if (pookie[4].flagUp)
                    iShowImage(pookie[4].x, pookie[4].y, donkyUp[pookie[4].upInd]);
                else if (pookie[4].flagDown)
                    iShowImage(pookie[4].x, pookie[4].y, donkyDown[pookie[4].downInd]);

                if (pookie[5].flagRight)
                    iShowImage(pookie[5].x, pookie[5].y, rinkyRight[pookie[5].rightInd]);
                else if (pookie[5].flagLeft)
                    iShowImage(pookie[5].x, pookie[5].y, rinkyLeft[pookie[5].leftInd]);
                else if (pookie[5].flagUp)
                    iShowImage(pookie[5].x, pookie[5].y, rinkyUp[pookie[5].upInd]);
                else if (pookie[5].flagDown)
                    iShowImage(pookie[5].x, pookie[5].y, rinkyDown[pookie[5].downInd]);
            }
        }

        else
        {
            if (selected == 1 || selected == 2)
            {
                if (blueGhost > 3)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (pookie[i].blueOn)
                        {
                            if (pookie[i].flagRight)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhost[pookie[i].rightInd]);
                            else if (pookie[i].flagLeft)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhost[pookie[i].leftInd]);
                            else if (pookie[i].flagUp)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhost[pookie[i].upInd]);
                            else if (pookie[i].flagDown)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhost[pookie[i].downInd]);
                        }
                        else
                        {
                            if (i == 0)
                            {
                                if (pookie[0].flagRight)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyRight[pookie[0].rightInd]);
                                else if (pookie[0].flagLeft)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyLeft[pookie[0].leftInd]);
                                else if (pookie[0].flagUp)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyUp[pookie[0].upInd]);
                                else if (pookie[0].flagDown)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyDown[pookie[0].downInd]);
                            }
                            else if (i == 1)
                            {
                                if (pookie[1].flagRight)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyRight[pookie[1].rightInd]);
                                else if (pookie[1].flagLeft)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyLeft[pookie[1].leftInd]);
                                else if (pookie[1].flagUp)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyUp[pookie[1].upInd]);
                                else if (pookie[1].flagDown)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyDown[pookie[1].downInd]);
                            }
                            else if (i == 2)
                            {
                                if (pookie[2].flagRight)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeRight[pookie[2].rightInd]);
                                else if (pookie[2].flagLeft)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeLeft[pookie[2].leftInd]);
                                else if (pookie[2].flagUp)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeUp[pookie[2].upInd]);
                                else if (pookie[2].flagDown)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeDown[pookie[2].downInd]);
                            }
                            else if (i == 3)
                            {
                                if (pookie[3].flagRight)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyRight[pookie[3].rightInd]);
                                else if (pookie[3].flagLeft)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyLeft[pookie[3].leftInd]);
                                else if (pookie[3].flagUp)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyUp[pookie[3].upInd]);
                                else if (pookie[3].flagDown)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyDown[pookie[3].downInd]);
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (pookie[i].blueOn)
                        {
                            if (pookie[i].flagRight)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhostEnd[pookie[i].rightInd]);
                            else if (pookie[i].flagLeft)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhostEnd[pookie[i].leftInd]);
                            else if (pookie[i].flagUp)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhostEnd[pookie[i].upInd]);
                            else if (pookie[i].flagDown)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhostEnd[pookie[i].downInd]);
                        }
                        else
                        {
                            if (i == 0)
                            {
                                if (pookie[0].flagRight)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyRight[pookie[0].rightInd]);
                                else if (pookie[0].flagLeft)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyLeft[pookie[0].leftInd]);
                                else if (pookie[0].flagUp)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyUp[pookie[0].upInd]);
                                else if (pookie[0].flagDown)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyDown[pookie[0].downInd]);
                            }
                            else if (i == 1)
                            {
                                if (pookie[1].flagRight)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyRight[pookie[1].rightInd]);
                                else if (pookie[1].flagLeft)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyLeft[pookie[1].leftInd]);
                                else if (pookie[1].flagUp)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyUp[pookie[1].upInd]);
                                else if (pookie[1].flagDown)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyDown[pookie[1].downInd]);
                            }
                            else if (i == 2)
                            {
                                if (pookie[2].flagRight)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeRight[pookie[2].rightInd]);
                                else if (pookie[2].flagLeft)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeLeft[pookie[2].leftInd]);
                                else if (pookie[2].flagUp)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeUp[pookie[2].upInd]);
                                else if (pookie[2].flagDown)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeDown[pookie[2].downInd]);
                            }
                            else if (i == 3)
                            {
                                if (pookie[3].flagRight)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyRight[pookie[3].rightInd]);
                                else if (pookie[3].flagLeft)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyLeft[pookie[3].leftInd]);
                                else if (pookie[3].flagUp)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyUp[pookie[3].upInd]);
                                else if (pookie[3].flagDown)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyDown[pookie[3].downInd]);
                            }
                        }
                    }
                }
            }

            else if (selected == 4 || selected == 3)
            {
                if (blueGhost > 5)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        if (pookie[i].blueOn)
                        {
                            if (pookie[i].flagRight)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhost[pookie[i].rightInd]);
                            else if (pookie[i].flagLeft)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhost[pookie[i].leftInd]);
                            else if (pookie[i].flagUp)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhost[pookie[i].upInd]);
                            else if (pookie[i].flagDown)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhost[pookie[i].downInd]);
                        }
                        else
                        {
                            if (i == 0)
                            {
                                if (pookie[0].flagRight)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyRight[pookie[0].rightInd]);
                                else if (pookie[0].flagLeft)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyLeft[pookie[0].leftInd]);
                                else if (pookie[0].flagUp)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyUp[pookie[0].upInd]);
                                else if (pookie[0].flagDown)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyDown[pookie[0].downInd]);
                            }
                            else if (i == 1)
                            {
                                if (pookie[1].flagRight)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyRight[pookie[1].rightInd]);
                                else if (pookie[1].flagLeft)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyLeft[pookie[1].leftInd]);
                                else if (pookie[1].flagUp)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyUp[pookie[1].upInd]);
                                else if (pookie[1].flagDown)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyDown[pookie[1].downInd]);
                            }
                            else if (i == 2)
                            {
                                if (pookie[2].flagRight)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeRight[pookie[2].rightInd]);
                                else if (pookie[2].flagLeft)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeLeft[pookie[2].leftInd]);
                                else if (pookie[2].flagUp)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeUp[pookie[2].upInd]);
                                else if (pookie[2].flagDown)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeDown[pookie[2].downInd]);
                            }
                            else if (i == 3)
                            {
                                if (pookie[3].flagRight)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyRight[pookie[3].rightInd]);
                                else if (pookie[3].flagLeft)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyLeft[pookie[3].leftInd]);
                                else if (pookie[3].flagUp)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyUp[pookie[3].upInd]);
                                else if (pookie[3].flagDown)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyDown[pookie[3].downInd]);
                            }
                            else if (i == 4)
                            {
                                if (pookie[4].flagRight)
                                    iShowImage(pookie[4].x, pookie[4].y, donkyRight[pookie[4].rightInd]);
                                else if (pookie[4].flagLeft)
                                    iShowImage(pookie[4].x, pookie[4].y, donkyLeft[pookie[4].leftInd]);
                                else if (pookie[4].flagUp)
                                    iShowImage(pookie[4].x, pookie[4].y, donkyUp[pookie[4].upInd]);
                                else if (pookie[4].flagDown)
                                    iShowImage(pookie[4].x, pookie[4].y, donkyDown[pookie[4].downInd]);
                            }
                            else if (i == 5)
                            {
                                if (pookie[5].flagRight)
                                    iShowImage(pookie[5].x, pookie[5].y, rinkyRight[pookie[5].rightInd]);
                                else if (pookie[5].flagLeft)
                                    iShowImage(pookie[5].x, pookie[5].y, rinkyLeft[pookie[5].leftInd]);
                                else if (pookie[5].flagUp)
                                    iShowImage(pookie[5].x, pookie[5].y, rinkyUp[pookie[5].upInd]);
                                else if (pookie[5].flagDown)
                                    iShowImage(pookie[5].x, pookie[5].y, rinkyDown[pookie[5].downInd]);
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < 6; i++)
                    {
                        if (pookie[i].blueOn)
                        {
                            if (pookie[i].flagRight)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhostEnd[pookie[i].rightInd]);
                            else if (pookie[i].flagLeft)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhostEnd[pookie[i].leftInd]);
                            else if (pookie[i].flagUp)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhostEnd[pookie[i].upInd]);
                            else if (pookie[i].flagDown)
                                iShowImage(pookie[i].x, pookie[i].y, frozenGhostEnd[pookie[i].downInd]);
                        }
                        else
                        {
                            if (i == 0)
                            {
                                if (pookie[0].flagRight)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyRight[pookie[0].rightInd]);
                                else if (pookie[0].flagLeft)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyLeft[pookie[0].leftInd]);
                                else if (pookie[0].flagUp)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyUp[pookie[0].upInd]);
                                else if (pookie[0].flagDown)
                                    iShowImage(pookie[0].x, pookie[0].y, inkyDown[pookie[0].downInd]);
                            }
                            else if (i == 1)
                            {
                                if (pookie[1].flagRight)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyRight[pookie[1].rightInd]);
                                else if (pookie[1].flagLeft)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyLeft[pookie[1].leftInd]);
                                else if (pookie[1].flagUp)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyUp[pookie[1].upInd]);
                                else if (pookie[1].flagDown)
                                    iShowImage(pookie[1].x, pookie[1].y, blinkyDown[pookie[1].downInd]);
                            }
                            else if (i == 2)
                            {
                                if (pookie[2].flagRight)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeRight[pookie[2].rightInd]);
                                else if (pookie[2].flagLeft)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeLeft[pookie[2].leftInd]);
                                else if (pookie[2].flagUp)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeUp[pookie[2].upInd]);
                                else if (pookie[2].flagDown)
                                    iShowImage(pookie[2].x, pookie[2].y, clydeDown[pookie[2].downInd]);
                            }
                            else if (i == 3)
                            {
                                if (pookie[3].flagRight)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyRight[pookie[3].rightInd]);
                                else if (pookie[3].flagLeft)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyLeft[pookie[3].leftInd]);
                                else if (pookie[3].flagUp)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyUp[pookie[3].upInd]);
                                else if (pookie[3].flagDown)
                                    iShowImage(pookie[3].x, pookie[3].y, pinkyDown[pookie[3].downInd]);
                            }
                            else if (i == 4)
                            {
                                if (pookie[4].flagRight)
                                    iShowImage(pookie[4].x, pookie[4].y, donkyRight[pookie[4].rightInd]);
                                else if (pookie[4].flagLeft)
                                    iShowImage(pookie[4].x, pookie[4].y, donkyLeft[pookie[4].leftInd]);
                                else if (pookie[4].flagUp)
                                    iShowImage(pookie[4].x, pookie[4].y, donkyUp[pookie[4].upInd]);
                                else if (pookie[4].flagDown)
                                    iShowImage(pookie[4].x, pookie[4].y, donkyDown[pookie[4].downInd]);
                            }
                            else if (i == 5)
                            {
                                if (pookie[5].flagRight)
                                    iShowImage(pookie[5].x, pookie[5].y, rinkyRight[pookie[5].rightInd]);
                                else if (pookie[5].flagLeft)
                                    iShowImage(pookie[5].x, pookie[5].y, rinkyLeft[pookie[5].leftInd]);
                                else if (pookie[5].flagUp)
                                    iShowImage(pookie[5].x, pookie[5].y, rinkyUp[pookie[5].upInd]);
                                else if (pookie[5].flagDown)
                                    iShowImage(pookie[5].x, pookie[5].y, rinkyDown[pookie[5].downInd]);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (congrats)
    {
        iShowImage(0, 0, scoreshowimage[congratsc]);
        iShowText(540, 300, pacScore, "text.ttf", 60);
    }

    else if (exitintro)
    {
        iShowImage(0, 0, exitimage[exitintroimage]);
    }
    else if (levelselect)
    {
        iShowImage(0, 0, levelselectimage[levelintro]);
    }
    else if (pause)
    {
        iShowImage(0, 0, pauseimage[pausec]);
    }
    else if (backgroundselector)
    {
        if (slbgimage == 1)
        {
            iShowImage(0, 0, slbg1[backgroundselectorc]);
            iSetColor(0, 0, 0);
            iShowText(45, 28, "BACK", "text.ttf", 50);
        }
        else if (slbgimage == 2)
        {
            iShowImage(0, 0, slbg2[backgroundselectorc]);
            iSetColor(0, 0, 0);
            iShowText(45, 28, "BACK", "text.ttf", 50);
        }
        else if (slbgimage == 3)
        {
            iShowImage(0, 0, slbg3[backgroundselectorc]);
            iSetColor(0, 0, 0);
            iShowText(45, 28, "BACK", "text.ttf", 50);
        }
        else if (slbgimage == 4)
        {
            iShowImage(0, 0, slbg4[backgroundselectorc]);
            iSetColor(0, 0, 0);
            iShowText(45, 28, "BACK", "text.ttf", 50);
        }
        else if (slbgimage == 5)
        {
            iShowImage(0, 0, slbg5[backgroundselectorc]);
            iSetColor(0, 0, 0);
            iShowText(45, 28, "BACK", "text.ttf", 50);
        }
        else if (slbgimage == 6)
        {
            iShowImage(0, 0, slbg6[backgroundselectorc]);
            iSetColor(0, 0, 0);
            iShowText(45, 28, "BACK", "text.ttf", 50);
        }
    }
};
void directionGenarator2(int ara[], int dir, int pookietype) // FOLLOWED SHUAIB SIR CODE
{
    if (ara[dir] == 0)
    {
        pookie[pookietype].flagLeft = 1;
    }
    else if (ara[dir] == 1)
    {
        pookie[pookietype].flagRight = 1;
    }
    else if (ara[dir] == 2)
    {
        pookie[pookietype].flagUp = 1;
    }
    else if (ara[dir] == 3)
    {
        pookie[pookietype].flagDown = 1;
    }
}
void directionGenarator(int a, int pookietype) // FOLLOWED SHUAIB SIR CODE
{
    time_t t;
    srand((unsigned)time(&t));
    int dir;
    pookie[pookietype].flagDown = 0;
    pookie[pookietype].flagLeft = 0;
    pookie[pookietype].flagRight = 0;
    pookie[pookietype].flagUp = 0;

    int para[4] = {-1, -1, -1, -1};
    int flag = 0;

    int distUp = calculateDistance(pookie[pookietype].x, pookie[pookietype].y + mazeCellWidth, pac.x, pac.y);
    int distDown = calculateDistance(pookie[pookietype].x, pookie[pookietype].y - mazeCellWidth, pac.x, pac.y);
    int distLeft = calculateDistance(pookie[pookietype].x - mazeCellWidth, pookie[pookietype].y, pac.x, pac.y);
    int distRight = calculateDistance(pookie[pookietype].x + mazeCellWidth, pookie[pookietype].y, pac.x, pac.y);
    int currentDist = calculateDistance(pookie[pookietype].x, pookie[pookietype].y, pac.x, pac.y);
    if (selected == 1)
    {
        if (a > 3)
        {
            if (!maze1[pookie[pookietype].cellY - 1][pookie[pookietype].cellX] && !flag)
            {
                if (distUp < currentDist)
                {
                    pookie[pookietype].flagUp = 1;
                    flag = 1;
                }
            }

            if (!maze1[pookie[pookietype].cellY + 1][pookie[pookietype].cellX] && !flag)
            {
                if (distDown < currentDist)
                {
                    pookie[pookietype].flagDown = 1;
                    flag = 1;
                }
            }

            if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX - 1] && !flag)
            {
                if (distLeft < currentDist)
                {
                    pookie[pookietype].flagLeft = 1;
                    flag = 1;
                }
            }

            if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX + 1] && !flag)
            {
                if (distRight < currentDist)
                {
                    pookie[pookietype].flagRight = 1;
                    flag = 1;
                }
            }

            if (!flag)
            {
                if (!maze1[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                    para[2] = 2;
                if (!maze1[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                    para[3] = 3;
                if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                    para[0] = 0;
                if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                    para[1] = 1;

                for (dir = rand() % 4; para[dir] == -1; dir = rand() % 4)
                    ;
                directionGenarator2(para, dir, pookietype);
            }
        }
        else
        {
            if (a == 0)
                pookie[pookietype].flagLeft = 1;
            else if (a == 1)
                pookie[pookietype].flagRight = 1;
            else if (a == 2)
                pookie[pookietype].flagUp = 1;
            else if (a == 3)
                pookie[pookietype].flagDown = 1;
        }
    }
    else if (selected == 2)
    {
        if (a > 3)
        {
            if (!maze2[pookie[pookietype].cellY - 1][pookie[pookietype].cellX] && !flag)
            {
                if (distUp < currentDist)
                {
                    pookie[pookietype].flagUp = 1;
                    flag = 1;
                }
            }

            if (!maze2[pookie[pookietype].cellY + 1][pookie[pookietype].cellX] && !flag)
            {
                if (distDown < currentDist)
                {
                    pookie[pookietype].flagDown = 1;
                    flag = 1;
                }
            }

            if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX - 1] && !flag)
            {
                if (distLeft < currentDist)
                {
                    pookie[pookietype].flagLeft = 1;
                    flag = 1;
                }
            }

            if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX + 1] && !flag)
            {
                if (distRight < currentDist)
                {
                    pookie[pookietype].flagRight = 1;
                    flag = 1;
                }
            }

            if (!flag)
            {
                if (!maze2[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                    para[2] = 2;
                if (!maze2[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                    para[3] = 3;
                if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                    para[0] = 0;
                if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                    para[1] = 1;

                for (dir = rand() % 4; para[dir] == -1; dir = rand() % 4)
                    ;
                directionGenarator2(para, dir, pookietype);
            }
        }
        else
        {
            if (a == 0)
                pookie[pookietype].flagLeft = 1;
            else if (a == 1)
                pookie[pookietype].flagRight = 1;
            else if (a == 2)
                pookie[pookietype].flagUp = 1;
            else if (a == 3)
                pookie[pookietype].flagDown = 1;
        }
    }
    else if (selected == 3)
    {
        if (a > 3)
        {
            if (!maze3[pookie[pookietype].cellY - 1][pookie[pookietype].cellX] && !flag)
            {
                if (distUp < currentDist)
                {
                    pookie[pookietype].flagUp = 1;
                    flag = 1;
                }
            }

            if (!maze3[pookie[pookietype].cellY + 1][pookie[pookietype].cellX] && !flag)
            {
                if (distDown < currentDist)
                {
                    pookie[pookietype].flagDown = 1;
                    flag = 1;
                }
            }

            if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX - 1] && !flag)
            {
                if (distLeft < currentDist)
                {
                    pookie[pookietype].flagLeft = 1;
                    flag = 1;
                }
            }

            if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX + 1] && !flag)
            {
                if (distRight < currentDist)
                {
                    pookie[pookietype].flagRight = 1;
                    flag = 1;
                }
            }

            if (!flag)
            {
                if (!maze3[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                    para[2] = 2;
                if (!maze3[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                    para[3] = 3;
                if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                    para[0] = 0;
                if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                    para[1] = 1;

                for (dir = rand() % 4; para[dir] == -1; dir = rand() % 4)
                    ;
                directionGenarator2(para, dir, pookietype);
            }
        }
        else
        {
            if (a == 0)
                pookie[pookietype].flagLeft = 1;
            else if (a == 1)
                pookie[pookietype].flagRight = 1;
            else if (a == 2)
                pookie[pookietype].flagUp = 1;
            else if (a == 3)
                pookie[pookietype].flagDown = 1;
        }
    }
    else if (selected == 4)
    {
        if (a > 3)
        {
            if (!maze4[pookie[pookietype].cellY - 1][pookie[pookietype].cellX] && !flag)
            {
                if (distUp < currentDist)
                {
                    pookie[pookietype].flagUp = 1;
                    flag = 1;
                }
            }

            if (!maze4[pookie[pookietype].cellY + 1][pookie[pookietype].cellX] && !flag)
            {
                if (distDown < currentDist)
                {
                    pookie[pookietype].flagDown = 1;
                    flag = 1;
                }
            }

            if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX - 1] && !flag)
            {
                if (distLeft < currentDist)
                {
                    pookie[pookietype].flagLeft = 1;
                    flag = 1;
                }
            }

            if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX + 1] && !flag)
            {
                if (distRight < currentDist)
                {
                    pookie[pookietype].flagRight = 1;
                    flag = 1;
                }
            }

            if (!flag)
            {
                if (!maze4[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                    para[2] = 2;
                if (!maze4[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                    para[3] = 3;
                if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                    para[0] = 0;
                if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                    para[1] = 1;

                for (dir = rand() % 4; para[dir] == -1; dir = rand() % 4)
                    ;
                directionGenarator2(para, dir, pookietype);
            }
        }
        else
        {
            if (a == 0)
                pookie[pookietype].flagLeft = 1;
            else if (a == 1)
                pookie[pookietype].flagRight = 1;
            else if (a == 2)
                pookie[pookietype].flagUp = 1;
            else if (a == 3)
                pookie[pookietype].flagDown = 1;
        }
    }
}

int calculateDistance(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}
void getGhostTarget(int pookietype, int *px, int *py)
{
    *px = pac.x;
    *py = pac.y;

    switch (pookietype)
    {

    case 1:
        if (pac.rightCount)
            *px += mazeCellWidth * 4;
        else if (pac.leftCount)
            *px -= mazeCellWidth * 4;
        else if (pac.upCount)
            *py += mazeCellWidth * 4;
        else if (pac.downCount)
            *py -= mazeCellWidth * 4;
        break;

    case 2:
        if (pac.rightCount)
            *px -= mazeCellWidth * 3;
        else if (pac.leftCount)
            *px += mazeCellWidth * 3;
        else if (pac.upCount)
            *py -= mazeCellWidth * 3;
        else if (pac.downCount)
            *py += mazeCellWidth * 3;
        break;

    case 3:
        // Predict intersection based on pac's direction and maze layout
        *px += (pac.rightCount ? 2 : pac.leftCount ? -2
                                                   : 0) *
               mazeCellWidth;
        *py += (pac.upCount ? 2 : pac.downCount ? -2
                                                : 0) *
               mazeCellWidth;
        break;

    case 4:
        *px += mazeCellWidth * (rand() % 5 - 2); // ±2 cells
        *py += mazeCellWidth * (rand() % 5 - 2);
        break;

    case 5:
        if (pac.x < mazeWidth / 2)
            *px = pac.x + mazeCellWidth * 2;
        else
            *px = pac.x - mazeCellWidth * 2;
        *py = pac.y;
        break;

    case 0:
        // Blast Mode: aggressively rush toward Pac with slight randomization
        *px = pac.x + mazeCellWidth * (rand() % 3 - 1); // offset ±1 cell horizontally
        *py = pac.y + mazeCellWidth * (rand() % 3 - 1); // offset ±1 cell vertically
        break;
    }
}

void pookiemovement()
{

    if (playingstart)
    {
        if (selected == 1 || selected == 2)
        {
            mazeX = 168;
            mazeY = 48;
            mazeWidth = 504;
            mazeHeight = 504;
        }
        else if (selected == 3)
        {
            mazeX = 72;
            mazeY = 48;
            mazeWidth = 864; // 36*mazeCellWidth
            mazeHeight = 456;
        }
        else if (selected == 4)
        {
            mazeX = 72;
            mazeY = 48;
            mazeWidth = 960;
            mazeHeight = 840;
        }
        if (selected == 1 || selected == 2)
        {

            for (int pookietype = 0; pookietype < 4; pookietype++)
            {
                int px = pac.x;
                int py = pac.y;
                if (scatter)
                {
                    switch (pookietype)
                    {
                    case 0: // Inky - Bottom Right
                        px = mazeX + mazeWidth - mazeCellWidth;
                        py = mazeY;
                        break;

                    case 1: // Blinky - Top Right
                        px = mazeX + mazeWidth - mazeCellWidth;
                        py = mazeY + mazeHeight - mazeCellWidth;
                        break;

                    case 2: // Pinky - Top Left
                        px = mazeX;
                        py = mazeY + mazeHeight - mazeCellWidth;
                        break;

                    case 3: // Clyde - Bottom Left
                        px = mazeX;
                        py = mazeY;
                        break;
                    }
                }
                if (blast)
                {
                    getGhostTarget(pookietype, &px, &py);
                }
                if (chase)
                {
                    // Calculate distance for Clyde logic
                    int distToPac = calculateDistance(pookie[pookietype].x, pookie[pookietype].y, pac.x, pac.y);

                    switch (pookietype)
                    {
                    case 0: // Inky - mimic behind + mirror
                        if (pac.rightCount)
                            px = pac.x - mazeCellWidth * 2;
                        else if (pac.leftCount)
                            px = pac.x + mazeCellWidth * 2;
                        else
                            px = pac.x;
                        py = pac.y; // Keep vertical center
                        break;

                    case 1: // Blinky - direct pursuit
                        px = pac.x;
                        py = pac.y;
                        break;

                    case 2: // Clyde - far chase, close scatter
                        if (distToPac > mazeCellWidth * mazeCellWidth * 9)
                        {
                            px = pac.x;
                            py = pac.y;
                        }
                        else
                        {
                            px = mazeX;
                            py = mazeY; // retreat to bottom left
                        }
                        break;

                    case 3: // Pinky - targets 4 tiles ahead
                        if (pac.rightCount)
                            px = pac.x + mazeCellWidth * 4;
                        else if (pac.leftCount)
                            px = pac.x - mazeCellWidth * 4;
                        else if (pac.upCount)
                            py = pac.y + mazeCellWidth * 4;
                        else if (pac.downCount)
                            py = pac.y - mazeCellWidth * 4;
                        else
                        {
                            px = pac.x;
                            py = pac.y;
                        }
                        break;
                    }
                }

                int distUp = calculateDistance(pookie[pookietype].x, pookie[pookietype].y + mazeCellWidth, px, py);
                int distDown = calculateDistance(pookie[pookietype].x, pookie[pookietype].y - mazeCellWidth, px, py);
                int distLeft = calculateDistance(pookie[pookietype].x - mazeCellWidth, pookie[pookietype].y, px, py);
                int distRight = calculateDistance(pookie[pookietype].x + mazeCellWidth, pookie[pookietype].y, px, py);
                int currentDist = calculateDistance(pookie[pookietype].x, pookie[pookietype].y, px, py);

                if (selected == 1)
                {
                    if (pookie[pookietype].flagRight) // 0123 → LRUD
                    {
                        if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                        {
                            pookie[pookietype].x += pookie[pookietype].speed;
                            pookie[pookietype].right++; // for animation timing

                            if (!(pookie[pookietype].right % 5))
                            {
                                pookie[pookietype].rightInd++;
                            }
                            if (pookie[pookietype].rightInd > 1)
                                pookie[pookietype].rightInd = 0;

                            // Directional flags
                            pookie[pookietype].flagRight = 1;
                            pookie[pookietype].flagLeft = 0;
                            pookie[pookietype].flagDown = 0;
                            pookie[pookietype].flagUp = 0;

                            if (!(pookie[pookietype].x % mazeCellWidth)) // Only update cell when aligned
                            {
                                pookie[pookietype].cellX++;

                                if (!maze1[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                                {
                                    if (distUp < currentDist)
                                        directionGenarator(2, pookietype);
                                }
                                else if (!maze1[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                                {
                                    if (distDown < currentDist)
                                        directionGenarator(3, pookietype);
                                }
                            }
                        }
                        else
                        {
                            directionGenarator(4, pookietype); // Continue forward if blocked
                        }
                    }
                    // DOWNWARD movement
                    else if (pookie[pookietype].flagDown)
                    {
                        if (!maze1[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                        {
                            pookie[pookietype].y -= pookie[pookietype].speed;
                            pookie[pookietype].down++;
                            if (!(pookie[pookietype].down % 5))
                                pookie[pookietype].downInd++;
                            if (pookie[pookietype].downInd > 1)
                                pookie[pookietype].downInd = 0;

                            pookie[pookietype].flagRight = 0;
                            pookie[pookietype].flagLeft = 0;
                            pookie[pookietype].flagDown = 1;
                            pookie[pookietype].flagUp = 0;

                            if (!(pookie[pookietype].y % mazeCellWidth))
                            {
                                pookie[pookietype].cellY++;

                                if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                                {
                                    if (distRight < currentDist)
                                        directionGenarator(1, pookietype);
                                }
                                else if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                                {
                                    if (distLeft < currentDist)
                                        directionGenarator(0, pookietype);
                                }
                            }
                        }
                        else
                            directionGenarator(4, pookietype);
                    }

                    // LEFTWARD movement
                    else if (pookie[pookietype].flagLeft)
                    {
                        if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                        {
                            pookie[pookietype].x -= pookie[pookietype].speed;
                            pookie[pookietype].left++;
                            if (!(pookie[pookietype].left % 5))
                                pookie[pookietype].leftInd++;
                            if (pookie[pookietype].leftInd > 1)
                                pookie[pookietype].leftInd = 0;

                            pookie[pookietype].flagRight = 0;
                            pookie[pookietype].flagLeft = 1;
                            pookie[pookietype].flagDown = 0;
                            pookie[pookietype].flagUp = 0;

                            if (!(pookie[pookietype].x % mazeCellWidth))
                            {
                                pookie[pookietype].cellX--;

                                if (!maze1[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                                {

                                    if (distUp < currentDist)
                                        directionGenarator(2, pookietype);
                                }
                                else if (!maze1[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                                {
                                    if (distDown < currentDist)
                                        directionGenarator(3, pookietype);
                                }
                            }
                        }
                        else
                            directionGenarator(4, pookietype);
                    }

                    // UPWARD movement
                    else if (pookie[pookietype].flagUp)
                    {
                        if (!maze1[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                        {
                            pookie[pookietype].y += pookie[pookietype].speed;
                            pookie[pookietype].up++;
                            if (!(pookie[pookietype].up % 5))
                                pookie[pookietype].upInd++;
                            if (pookie[pookietype].upInd > 1)
                                pookie[pookietype].upInd = 0;

                            pookie[pookietype].flagRight = 0;
                            pookie[pookietype].flagLeft = 0;
                            pookie[pookietype].flagDown = 0;
                            pookie[pookietype].flagUp = 1;

                            if (!(pookie[pookietype].y % mazeCellWidth))
                            {
                                pookie[pookietype].cellY--;

                                if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                                {
                                    if (distRight < currentDist)
                                        directionGenarator(1, pookietype);
                                }
                                else if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                                {
                                    if (distLeft < currentDist)
                                        directionGenarator(0, pookietype);
                                }
                            }
                        }
                        else
                            directionGenarator(4, pookietype);
                    }
                }
                if (selected == 2)
                {
                    if (pookie[pookietype].flagRight)
                    {
                        if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                        {
                            pookie[pookietype].x += pookie[pookietype].speed;
                            pookie[pookietype].right++;
                            if (!(pookie[pookietype].right % 5))
                                pookie[pookietype].rightInd++;
                            if (pookie[pookietype].rightInd > 1)
                                pookie[pookietype].rightInd = 0;

                            pookie[pookietype].flagRight = 1;
                            pookie[pookietype].flagLeft = 0;
                            pookie[pookietype].flagDown = 0;
                            pookie[pookietype].flagUp = 0;

                            if (!(pookie[pookietype].x % mazeCellWidth))
                            {
                                pookie[pookietype].cellX++;

                                if (!maze2[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                                {
                                    if (distUp < currentDist)
                                        directionGenarator(2, pookietype);
                                }
                                else if (!maze2[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                                {
                                    if (distDown < currentDist)
                                        directionGenarator(3, pookietype);
                                }
                            }
                        }
                        else
                            directionGenarator(4, pookietype);
                    }

                    else if (pookie[pookietype].flagDown)
                    {
                        if (!maze2[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                        {
                            pookie[pookietype].y -= pookie[pookietype].speed;
                            pookie[pookietype].down++;
                            if (!(pookie[pookietype].down % 5))
                                pookie[pookietype].downInd++;
                            if (pookie[pookietype].downInd > 1)
                                pookie[pookietype].downInd = 0;

                            pookie[pookietype].flagRight = 0;
                            pookie[pookietype].flagLeft = 0;
                            pookie[pookietype].flagDown = 1;
                            pookie[pookietype].flagUp = 0;

                            if (!(pookie[pookietype].y % mazeCellWidth))
                            {
                                pookie[pookietype].cellY++;

                                if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                                {
                                    if (distRight < currentDist)
                                        directionGenarator(1, pookietype);
                                }
                                else if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                                {
                                    if (distLeft < currentDist)
                                        directionGenarator(0, pookietype);
                                }
                            }
                        }
                        else
                            directionGenarator(4, pookietype);
                    }

                    else if (pookie[pookietype].flagLeft)
                    {
                        if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                        {
                            pookie[pookietype].x -= pookie[pookietype].speed;
                            pookie[pookietype].left++;
                            if (!(pookie[pookietype].left % 5))
                                pookie[pookietype].leftInd++;
                            if (pookie[pookietype].leftInd > 1)
                                pookie[pookietype].leftInd = 0;

                            pookie[pookietype].flagRight = 0;
                            pookie[pookietype].flagLeft = 1;
                            pookie[pookietype].flagDown = 0;
                            pookie[pookietype].flagUp = 0;

                            if (!(pookie[pookietype].x % mazeCellWidth))
                            {
                                pookie[pookietype].cellX--;

                                if (!maze2[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                                {

                                    if (distUp < currentDist)
                                        directionGenarator(2, pookietype);
                                }
                                else if (!maze2[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                                {
                                    if (distDown < currentDist)
                                        directionGenarator(3, pookietype);
                                }
                            }
                        }
                        else
                            directionGenarator(4, pookietype);
                    }

                    else if (pookie[pookietype].flagUp)
                    {
                        if (!maze2[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                        {
                            pookie[pookietype].y += pookie[pookietype].speed;
                            pookie[pookietype].up++;
                            if (!(pookie[pookietype].up % 5))
                                pookie[pookietype].upInd++;
                            if (pookie[pookietype].upInd > 1)
                                pookie[pookietype].upInd = 0;

                            pookie[pookietype].flagRight = 0;
                            pookie[pookietype].flagLeft = 0;
                            pookie[pookietype].flagDown = 0;
                            pookie[pookietype].flagUp = 1;

                            if (!(pookie[pookietype].y % mazeCellWidth))
                            {
                                pookie[pookietype].cellY--;

                                if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                                {
                                    if (distRight < currentDist)
                                        directionGenarator(1, pookietype);
                                }
                                else if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                                {
                                    if (distLeft < currentDist)
                                        directionGenarator(0, pookietype);
                                }
                            }
                        }
                        else
                            directionGenarator(4, pookietype);
                    }
                }
            }
        }
    }
    if (selected == 3 || selected == 4)
    {

        for (int pookietype = 0; pookietype < 6; pookietype++)
        {
            int px = pac.x;
            int py = pac.y;
            if (scatter)
            {
                switch (pookietype)
                {
                case 0: // Inky - Bottom Right
                    px = mazeX + mazeWidth - mazeCellWidth;
                    py = mazeY;
                    break;

                case 1: // Blinky - Top Right
                    px = mazeX + mazeWidth - mazeCellWidth;
                    py = mazeY + mazeHeight - mazeCellWidth;
                    break;

                case 2: // Pinky - Top Left
                    px = mazeX;
                    py = mazeY + mazeHeight - mazeCellWidth;
                    break;

                case 3: // Clyde - Bottom Left
                    px = mazeX;
                    py = mazeY;
                    break;

                case 4: // Donky - Left Middle
                    px = mazeX;
                    py = mazeY + mazeHeight / 2;
                    break;

                case 5: // Rinky - Maze Center
                    px = mazeX + mazeWidth / 2;
                    py = mazeY + mazeHeight / 2;
                    break;
                }
            }

            if (blast)
            {
                getGhostTarget(pookietype, &px, &py);
            }

            if (chase)
            {
                // Calculate distance for Clyde logic
                int distToPac = calculateDistance(pookie[pookietype].x, pookie[pookietype].y, pac.x, pac.y);

                switch (pookietype)
                {
                case 0: // Inky - mimic behind + mirror
                    if (pac.rightCount)
                        px = pac.x - mazeCellWidth * 2;
                    else if (pac.leftCount)
                        px = pac.x + mazeCellWidth * 2;
                    else
                        px = pac.x;
                    py = pac.y; // Keep vertical center
                    break;

                case 1: // Blinky - direct pursuit
                    px = pac.x;
                    py = pac.y;
                    break;

                case 2: // Clyde - far chase, close scatter
                    if (distToPac > mazeCellWidth * mazeCellWidth * 9)
                    {
                        px = pac.x;
                        py = pac.y;
                    }
                    else
                    {
                        px = mazeX;
                        py = mazeY; // retreat to bottom left
                    }
                    break;

                case 3: // Pinky - targets 4 tiles ahead
                    if (pac.rightCount)
                        px = pac.x + mazeCellWidth * 4;
                    else if (pac.leftCount)
                        px = pac.x - mazeCellWidth * 4;
                    else if (pac.upCount)
                        py = pac.y + mazeCellWidth * 4;
                    else if (pac.downCount)
                        py = pac.y - mazeCellWidth * 4;
                    else
                    {
                        px = pac.x;
                        py = pac.y;
                    }
                    break;

                case 4: // Donky - uses wall-hugging offset
                    px = pac.x + (pac.x < mazeX + mazeWidth / 2 ? mazeCellWidth : -mazeCellWidth);
                    py = pac.y;
                    break;

                case 5: // Rinky - semi-random jitter toward Pac
                    px = pac.x + mazeCellWidth * (rand() % 3 - 1);
                    py = pac.y + mazeCellWidth * (rand() % 3 - 1);
                    break;
                }
            }

            int distUp = calculateDistance(pookie[pookietype].x, pookie[pookietype].y + mazeCellWidth, px, py);
            int distDown = calculateDistance(pookie[pookietype].x, pookie[pookietype].y - mazeCellWidth, px, py);
            int distLeft = calculateDistance(pookie[pookietype].x - mazeCellWidth, pookie[pookietype].y, px, py);
            int distRight = calculateDistance(pookie[pookietype].x + mazeCellWidth, pookie[pookietype].y, px, py);
            int currentDist = calculateDistance(pookie[pookietype].x, pookie[pookietype].y, px, py);

            if (selected == 3)
            {
                if (pookie[pookietype].flagRight)
                {
                    if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                    {
                        pookie[pookietype].x += pookie[pookietype].speed;
                        pookie[pookietype].right++;
                        if (!(pookie[pookietype].right % 5))
                            pookie[pookietype].rightInd++;
                        if (pookie[pookietype].rightInd > 1)
                            pookie[pookietype].rightInd = 0;
                        pookie[pookietype].flagRight = 1;
                        pookie[pookietype].flagLeft = 0;
                        pookie[pookietype].flagDown = 0;
                        pookie[pookietype].flagUp = 0;

                        if (!(pookie[pookietype].x % mazeCellWidth))
                        {
                            pookie[pookietype].cellX++;
                            if (!maze3[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                            {
                                if (distUp < currentDist)
                                    directionGenarator(2, pookietype);
                            }
                            else if (!maze3[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                            {
                                if (distDown < currentDist)
                                    directionGenarator(3, pookietype);
                            }
                        }
                    }
                    else
                        directionGenarator(4, pookietype);
                }
                else if (pookie[pookietype].flagDown)
                {
                    if (!maze3[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                    {
                        pookie[pookietype].y -= pookie[pookietype].speed;
                        pookie[pookietype].down++;
                        if (!(pookie[pookietype].down % 5))
                            pookie[pookietype].downInd++;
                        if (pookie[pookietype].downInd > 1)
                            pookie[pookietype].downInd = 0;
                        pookie[pookietype].flagRight = 0;
                        pookie[pookietype].flagLeft = 0;
                        pookie[pookietype].flagDown = 1;
                        pookie[pookietype].flagUp = 0;

                        if (!(pookie[pookietype].y % mazeCellWidth))
                        {
                            pookie[pookietype].cellY++;
                            if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                            {
                                if (distRight < currentDist)
                                    directionGenarator(1, pookietype);
                            }
                            else if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                            {
                                if (distLeft < currentDist)
                                    directionGenarator(0, pookietype);
                            }
                        }
                    }
                    else
                        directionGenarator(4, pookietype);
                }
                else if (pookie[pookietype].flagLeft)
                {
                    if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                    {
                        pookie[pookietype].x -= pookie[pookietype].speed;
                        pookie[pookietype].left++;
                        if (!(pookie[pookietype].left % 5))
                            pookie[pookietype].leftInd++;
                        if (pookie[pookietype].leftInd > 1)
                            pookie[pookietype].leftInd = 0;
                        pookie[pookietype].flagRight = 0;
                        pookie[pookietype].flagLeft = 1;
                        pookie[pookietype].flagDown = 0;
                        pookie[pookietype].flagUp = 0;

                        if (!(pookie[pookietype].x % mazeCellWidth))
                        {
                            pookie[pookietype].cellX--;
                            if (!maze3[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                            {
                                if (distUp < currentDist)
                                    directionGenarator(2, pookietype);
                            }
                            else if (!maze3[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                            {
                                if (distDown < currentDist)
                                    directionGenarator(3, pookietype);
                            }
                        }
                    }
                    else
                        directionGenarator(4, pookietype);
                }
                else if (pookie[pookietype].flagUp)
                {
                    if (!maze3[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                    {
                        pookie[pookietype].y += pookie[pookietype].speed;
                        pookie[pookietype].up++;
                        if (!(pookie[pookietype].up % 5))
                            pookie[pookietype].upInd++;
                        if (pookie[pookietype].upInd > 1)
                            pookie[pookietype].upInd = 0;
                        pookie[pookietype].flagRight = 0;
                        pookie[pookietype].flagLeft = 0;
                        pookie[pookietype].flagDown = 0;
                        pookie[pookietype].flagUp = 1;

                        if (!(pookie[pookietype].y % mazeCellWidth))
                        {
                            pookie[pookietype].cellY--;
                            if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                            {
                                if (distRight < currentDist)
                                    directionGenarator(1, pookietype);
                            }
                            else if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                            {
                                if (distLeft < currentDist)
                                    directionGenarator(0, pookietype);
                            }
                        }
                    }
                    else
                        directionGenarator(4, pookietype);
                }
            }
            if (selected == 4)
            {
                if (pookie[pookietype].flagRight)
                {
                    if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                    {
                        pookie[pookietype].x += pookie[pookietype].speed;
                        pookie[pookietype].right++;
                        if (!(pookie[pookietype].right % 5))
                            pookie[pookietype].rightInd++;
                        if (pookie[pookietype].rightInd > 1)
                            pookie[pookietype].rightInd = 0;
                        pookie[pookietype].flagRight = 1;
                        pookie[pookietype].flagLeft = 0;
                        pookie[pookietype].flagDown = 0;
                        pookie[pookietype].flagUp = 0;

                        if (!(pookie[pookietype].x % mazeCellWidth))
                        {
                            pookie[pookietype].cellX++;
                            if (!maze4[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                            {
                                if (distUp < currentDist)
                                    directionGenarator(2, pookietype);
                            }
                            else if (!maze4[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                            {
                                if (distDown < currentDist)
                                    directionGenarator(3, pookietype);
                            }
                        }
                    }
                    else
                        directionGenarator(4, pookietype);
                }
                else if (pookie[pookietype].flagDown)
                {
                    if (!maze4[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                    {
                        pookie[pookietype].y -= pookie[pookietype].speed;
                        pookie[pookietype].down++;
                        if (!(pookie[pookietype].down % 5))
                            pookie[pookietype].downInd++;
                        if (pookie[pookietype].downInd > 1)
                            pookie[pookietype].downInd = 0;
                        pookie[pookietype].flagRight = 0;
                        pookie[pookietype].flagLeft = 0;
                        pookie[pookietype].flagDown = 1;
                        pookie[pookietype].flagUp = 0;

                        if (!(pookie[pookietype].y % mazeCellWidth))
                        {
                            pookie[pookietype].cellY++;
                            if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                            {
                                if (distRight < currentDist)
                                    directionGenarator(1, pookietype);
                            }
                            else if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                            {
                                if (distLeft < currentDist)
                                    directionGenarator(0, pookietype);
                            }
                        }
                    }
                    else
                        directionGenarator(4, pookietype);
                }
                else if (pookie[pookietype].flagLeft)
                {
                    if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                    {
                        pookie[pookietype].x -= pookie[pookietype].speed;
                        pookie[pookietype].left++;
                        if (!(pookie[pookietype].left % 5))
                            pookie[pookietype].leftInd++;
                        if (pookie[pookietype].leftInd > 1)
                            pookie[pookietype].leftInd = 0;
                        pookie[pookietype].flagRight = 0;
                        pookie[pookietype].flagLeft = 1;
                        pookie[pookietype].flagDown = 0;
                        pookie[pookietype].flagUp = 0;

                        if (!(pookie[pookietype].x % mazeCellWidth))
                        {
                            pookie[pookietype].cellX--;
                            if (!maze4[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                            {
                                if (distUp < currentDist)
                                    directionGenarator(2, pookietype);
                            }
                            else if (!maze4[pookie[pookietype].cellY + 1][pookie[pookietype].cellX])
                            {
                                if (distDown < currentDist)
                                    directionGenarator(3, pookietype);
                            }
                        }
                    }
                    else
                        directionGenarator(4, pookietype);
                }
                else if (pookie[pookietype].flagUp)
                {
                    if (!maze4[pookie[pookietype].cellY - 1][pookie[pookietype].cellX])
                    {
                        pookie[pookietype].y += pookie[pookietype].speed;
                        pookie[pookietype].up++;
                        if (!(pookie[pookietype].up % 5))
                            pookie[pookietype].upInd++;
                        if (pookie[pookietype].upInd > 1)
                            pookie[pookietype].upInd = 0;
                        pookie[pookietype].flagRight = 0;
                        pookie[pookietype].flagLeft = 0;
                        pookie[pookietype].flagDown = 0;
                        pookie[pookietype].flagUp = 1;

                        if (!(pookie[pookietype].y % mazeCellWidth))
                        {
                            pookie[pookietype].cellY--;
                            if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX + 1])
                            {
                                if (distRight < currentDist)
                                    directionGenarator(1, pookietype);
                            }
                            else if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX - 1])
                            {
                                if (distLeft < currentDist)
                                    directionGenarator(0, pookietype);
                            }
                        }
                    }
                    else
                        directionGenarator(4, pookietype);
                }
            }
        }
    }
}
void pacmanmovement()
{
    if (selected == 1)
    {
        if (pac.rightCount)
        {
            pac.right++;
            if (!maze1[cellY][cellX + 1])
            {
                pac.x += pacspeed;
                if (!(pac.right % 2))
                    pac.rightInd++;

                if (!(pac.x % mazeCellWidth))
                    cellX++;
            }
            if (pac.rightInd > 1)
                pac.rightInd = 0;
        }
        else if (pac.leftCount)
        {
            pac.left++;
            if (!maze1[cellY][cellX - 1])
            {
                pac.x -= pacspeed;
                if (!(pac.left % 2))
                    pac.leftInd++;

                if (!(pac.x % mazeCellWidth))
                    cellX--;
            }
            if (pac.leftInd > 1)
                pac.leftInd = 0;
        }
        else if (pac.upCount)
        {
            pac.up++;
            if (!maze1[cellY - 1][cellX])
            {
                pac.y += pacspeed;
                if (!(pac.up % 2))
                    pac.upInd++;

                if (!(pac.y % mazeCellWidth))
                    cellY--;
            }
            if (pac.upInd > 1)
                pac.upInd = 0;
        }
        else if (pac.downCount)
        {
            pac.down++;
            if (!maze1[cellY + 1][cellX])
            {
                pac.y -= pacspeed;
                if (!(pac.down % 2))
                    pac.downInd++;

                if (!(pac.y % mazeCellWidth))
                    cellY++;
            }
            if (pac.downInd > 1)
                pac.downInd = 0;
        }
    }
    else if (selected == 2)
    {
        if (pac.rightCount)
        {
            pac.right++;
            if (!maze2[cellY][cellX + 1])
            {
                pac.x += pacspeed;
                if (!(pac.right % 2))
                    pac.rightInd++;

                if (!(pac.x % mazeCellWidth))
                    cellX++;
            }
            if (pac.rightInd > 1)
                pac.rightInd = 0;
        }
        else if (pac.leftCount)
        {
            pac.left++;
            if (!maze2[cellY][cellX - 1])
            {
                pac.x -= pacspeed;
                if (!(pac.left % 2))
                    pac.leftInd++;

                if (!(pac.x % mazeCellWidth))
                    cellX--;
            }
            if (pac.leftInd > 1)
                pac.leftInd = 0;
        }
        else if (pac.upCount)
        {
            pac.up++;
            if (!maze2[cellY - 1][cellX])
            {
                pac.y += pacspeed;
                if (!(pac.up % 2))
                    pac.upInd++;

                if (!(pac.y % mazeCellWidth))
                    cellY--;
            }
            if (pac.upInd > 1)
                pac.upInd = 0;
        }
        else if (pac.downCount)
        {
            pac.down++;
            if (!maze2[cellY + 1][cellX])
            {
                pac.y -= pacspeed;
                if (!(pac.down % 2))
                    pac.downInd++;

                if (!(pac.y % mazeCellWidth))
                    cellY++;
            }
            if (pac.downInd > 1)
                pac.downInd = 0;
        }
    }

    else if (selected == 3)
    {
        if (pac.rightCount)
        {
            pac.right++;
            if (!maze3[cellY][cellX + 1])
            {
                pac.x += pacspeed;
                if (!(pac.right % 2))
                    pac.rightInd++;

                if (!(pac.x % mazeCellWidth))
                    cellX++;
            }
            if (pac.rightInd > 1)
                pac.rightInd = 0;
        }
        else if (pac.leftCount)
        {
            pac.left++;
            if (!maze3[cellY][cellX - 1])
            {
                pac.x -= pacspeed;
                if (!(pac.left % 2))
                    pac.leftInd++;

                if (!(pac.x % mazeCellWidth))
                    cellX--;
            }
            if (pac.leftInd > 1)
                pac.leftInd = 0;
        }
        else if (pac.upCount)
        {
            pac.up++;
            if (!maze3[cellY - 1][cellX])
            {
                pac.y += pacspeed;
                if (!(pac.up % 2))
                    pac.upInd++;

                if (!(pac.y % mazeCellWidth))
                    cellY--;
            }
            if (pac.upInd > 1)
                pac.upInd = 0;
        }
        else if (pac.downCount)
        {
            pac.down++;
            if (!maze3[cellY + 1][cellX])
            {
                pac.y -= pacspeed;
                if (!(pac.down % 2))
                    pac.downInd++;

                if (!(pac.y % mazeCellWidth))
                    cellY++;
            }
            if (pac.downInd > 1)
                pac.downInd = 0;
        }
    }
    else if (selected == 4)
    {
        if (pac.rightCount)
        {
            pac.right++;
            if (!maze4[cellY][cellX + 1])
            {
                pac.x += pacspeed;
                if (!(pac.right % 2))
                    pac.rightInd++;

                if (!(pac.x % mazeCellWidth))
                    cellX++;
            }
            if (pac.rightInd > 1)
                pac.rightInd = 0;
        }
        else if (pac.leftCount)
        {
            pac.left++;
            if (!maze4[cellY][cellX - 1])
            {
                pac.x -= pacspeed;
                if (!(pac.left % 2))
                    pac.leftInd++;

                if (!(pac.x % mazeCellWidth))
                    cellX--;
            }
            if (pac.leftInd > 1)
                pac.leftInd = 0;
        }
        else if (pac.upCount)
        {
            pac.up++;
            if (!maze4[cellY - 1][cellX])
            {
                pac.y += pacspeed;
                if (!(pac.up % 2))
                    pac.upInd++;

                if (!(pac.y % mazeCellWidth))
                    cellY--;
            }
            if (pac.upInd > 1)
                pac.upInd = 0;
        }
        else if (pac.downCount)
        {
            pac.down++;
            if (!maze4[cellY + 1][cellX])
            {
                pac.y -= pacspeed;
                if (!(pac.down % 2))
                    pac.downInd++;

                if (!(pac.y % mazeCellWidth))
                    cellY++;
            }
            if (pac.downInd > 1)
                pac.downInd = 0;
        }
    }
}
void iMouseDrag(int mx, int my)
{
    // place your codes here
}
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
}
void iMouseMove(int mx, int my)
{
    if (mainmenu)
    {
        if (mx >= 382 && my >= 579 && mx <= 765 && my <= 661)
        {
            menuc = 8;
        }
        else if (mx >= 425 && my >= 476 && mx <= 678 && my <= 508)
        {
            menuc = 1;
        }
        else if (mx >= 417 && my >= 404 && mx <= 697 && my <= 437)
        {
            menuc = 2;
        }
        else if (mx >= 424 && my >= 331 && mx <= 631 && my <= 357)
        {
            menuc = 3;
        }
        else if (mx >= 423 && my >= 253 && mx <= 670 && my <= 285)
        {
            menuc = 4;
        }
        else if (mx >= 424 && my >= 184 && mx <= 613 && my <= 211)
        {
            menuc = 5;
        }
        else if (mx >= 419 && my >= 32 && mx <= 529 && my <= 71)
        {
            menuc = 7;
        }
        else if (mx >= 415 && my >= 109 && mx <= 565 && my <= 136)
        {
            menuc = 6;
        }
        else
            menuc = 0;
    }
    else if (highscore)
    {
        if ((mx >= 1040 && mx <= 1150) && (my >= 42 && my <= 88))
        {
            highscorec = 1;
        }
        else
            highscorec = 0;
    }

    else if (settings)
    {
        if (soundOn)
        {
            if ((mx >= 408 && mx <= 783) && (my >= 388 && my <= 439))
            {
                settingsc = 1;
            }
            else if ((mx >= 380 && mx <= 828) && (my >= 277 && my <= 320))
            {
                settingsc = 2;
            }
            else if ((mx >= 964 && mx <= 1172) && (my >= 59 && my <= 115))
            {
                settingsc = 3;
            }
            else
            {
                settingsc = 0;
            }
        }
        else if (soundOn == 0)
        {
            if ((mx >= 408 && mx <= 783) && (my >= 388 && my <= 439))
            {
                settingsc = 5;
            }
            else if ((mx >= 380 && mx <= 828) && (my >= 277 && my <= 320))
            {
                settingsc = 6;
            }
            else if ((mx >= 964 && mx <= 1172) && (my >= 59 && my <= 115))
            {
                settingsc = 7;
            }
            else
                settingsc = 4;
        }
    }

    else if (pause)
    {
        if (mx >= 257 && my >= 420 && mx <= 698 && my <= 494)
        {
            pausec = 1;
        }
        else if (mx >= 261 && my >= 299 && mx <= 534 && my <= 372)
        {
            pausec = 2;
        }
        else if (mx >= 270 && my >= 178 && mx <= 928 && my <= 251)
        {
            pausec = 3;
        }
        else
            pausec = 0;
    }
    else if (credits)
    {
        if ((mx >= 957 && mx <= 1182) && (my >= 36 && my <= 104))
        {
            creditsc = 1;
        }
        else
            creditsc = 0;
    }
    else if (quit)
    {
        if ((mx >= 289 && mx <= 415) && (my >= 245 && my <= 299))
        {
            quitc = 1;
        }
        else if ((mx >= 741 && mx <= 858) && (my >= 252 && my <= 302))
        {
            quitc = 2;
        }
        else
            quitc = 0;
    }
}
void resumeGameSession()
{

    loadGameStat();        // Loads full saved game state
    foodCoordinateStore(); // Re-align map coordinates based on selected maze
    resumeimage = 0;
    mainmenu = 0;     // Exits menu screen
    playingstart = 1; // Enables gameplay mode
    iResumeAll();
    iPauseSound(sound4); // Restarts timers for movement & events/ Restarts timers for movement & events
}

void Reset()
{
    pookieinitialcoordinate();
    PacmanInitialCoordinate();
}
void iMouseClick(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (soundOn)
            iPlaySound("sound/keypress.wav", 0, 50);
        printf("mx=%d my=%d", mx, my);
        if (mainmenu)
        {
            if (mx >= 382 && my >= 579 && mx <= 765 && my <= 661)
            {
                specialthanks = 1;
                mainmenu = 0;
                resumeimage = 0;
                resumec = 0;
                if (soundOn)
                {
                    iStopSound(sound1);
                    iPauseSound(sound4);
                }
            }
            else if (mx >= 425 && my >= 476 && mx <= 678 && my <= 508)
            {
                playgameintro = 1;
                mainmenu = 0;
                resumeimage = 0;
                if (soundOn)
                {
                    iStopSound(sound1);
                }
                resumec = 0;
            }
            else if (mx >= 417 && my >= 404 && mx <= 697 && my <= 437)
            {
                highscore = 1;
                mainmenu = 0;
                resumeimage = 0;
                if (soundOn)
                {
                    iStopSound(sound1);
                    iPauseSound(sound4);
                }
                resumec = 0;
            }
            else if (mx >= 424 && my >= 331 && mx <= 631 && my <= 357)
            {
                settings = 1;
                mainmenu = 0;
                resumeimage = 0;
                {
                    iStopSound(sound1);
                    iPauseSound(sound4);
                }
                resumec = 0;
            }
            else if (mx >= 423 && my >= 253 && mx <= 670 && my <= 285)
            {
                difficulty = 1;
                mainmenu = 0;
                resumeimage = 0;
                if (soundOn)
                {
                    iStopSound(sound1);
                    iPauseSound(sound4);
                }
                resumec = 0;
            }
            else if (mx >= 424 && my >= 184 && mx <= 613 && my <= 211)
            {
                credits = 1;
                mainmenu = 0;
                resumeimage = 0;
                if (soundOn)
                {
                    iStopSound(sound1);
                    iPauseSound(sound4);
                }
                resumec = 0;
            }
            else if (mx >= 419 && my >= 32 && mx <= 529 && my <= 71)
            {
                quit = 1;
                mainmenu = 0;
                resumeimage = 0;
                if (soundOn)
                {
                    iStopSound(sound1);
                    iPauseSound(sound4);
                }
                resumec = 0;
            }
            else if (mx >= 415 && my >= 109 && mx <= 565 && my <= 136) // Rules button
            {
                if (soundOn)
                {
                    iStopSound(sound1);
                    iPauseSound(sound4);
                }
                rules = 1;
                mainmenu = 0;
                rulescene = 0; //  Reset scene index
                back = 0;      //  Ensure forward animation starts
                resumec = 0;
                resumeimage = 0;
            }
        }
        if (resumeimage)
        {
            if (mx >= 73 && my >= 485 && mx <= 323 && my <= 555)
            {
                resumeimage = 0;
                load = 1;
                // resumeGameSession();
            }
        }
        else if (specialthanks)
        {
            if (mx >= 1032 && my >= 44 && mx <= 1150 && my <= 94)
            {
                mainmenu = 1;
                specialthanks = 0;
                if (soundOn)
                    iResumeSound(sound4);
                resumeimage = 1;
            }
        }
        else if (highscore)
        {
            if ((mx >= 1040 && mx <= 1150) && (my >= 42 && my <= 88))
            {
                highscore = 0;
                mainmenu = 1;
                if (soundOn)
                    iResumeSound(sound4);
                resumeimage = 1;
            }
        }
        else if (difficulty)
        {
            if (mx >= 29 && my >= 23 && mx <= 184 && my <= 73)
            {
                difficulty = 0;
                mainmenu = 1;
                if (soundOn)
                    iResumeSound(sound4);
                resumeimage = 1;
            }
            else if (mx >= 80 && my >= 345 && mx <= 358 && my <= 515)
            {
                diffSpeed = 2;
                difficultyc = 0;
            }
            else if ((mx >= 139 && my >= 102 && mx <= 447 && my <= 263))
            {
                diffSpeed = 3;
                difficultyc = 1;
            }
            else if (mx >= 787 && my >= 96 && mx <= 1090 && my <= 297)
            {
                diffSpeed = 4;
                difficultyc = 2;
            }
            else if (mx >= 844 && my >= 337 && mx <= 1140 && my <= 537)
            {
                diffSpeed = 4;
                difficultyc = 3;
                pacspeed = 4;
                chase = 1;
            }
        }
        else if (playgameintro)
        {
            if (my >= 58 && mx >= 35 && my <= 109 && mx <= 183)
            {
                playgameintro = 0;
                mainmenu = 1;
                resumeimage = 1;
            }
            else if (mx >= 301 && my >= 245 && mx <= 866 && my <= 339)
            {
                typingName = 1;
            }
        }
        else if (settings)
        {
            if (soundOn)
            {
                if ((mx >= 408 && mx <= 783) && (my >= 388 && my <= 439))
                {
                    soundOn = 0;
                    if (soundOn & !settings)
                    {
                        iPauseSound(sound4);
                    }
                    //    iPauseAllSound();
                }
                else if ((mx >= 380 && mx <= 828) && (my >= 277 && my <= 320))
                {
                    mazeselector = 1;
                    settings = 0;
                }
                else if ((mx >= 964 && mx <= 1172) && (my >= 59 && my <= 115))
                {
                    settings = 0;
                    mainmenu = 1;
                    resumeimage = 1;
                    if (soundOn & !settings)
                        iResumeSound(sound4);
                }
            }
            else
            {
                if ((mx >= 408 && mx <= 783) && (my >= 388 && my <= 439))
                {
                    soundOn = 1;
                    if (soundOn & !settings)
                        iResumeSound(sound4);
                    //  iResumeAllSound();
                }
                else if ((mx >= 380 && mx <= 828) && (my >= 277 && my <= 320))
                {
                    mazeselector = 1;
                    settings = 0;
                }
                else if ((mx >= 964 && mx <= 1172) && (my >= 59 && my <= 115))
                {
                    settings = 0;
                    mainmenu = 1;
                    resumeimage = 1;
                    if (soundOn)
                        iResumeSound(sound4);
                }
            }
        }
        else if (mazeselector)
        {
            if (mx >= 146 && my >= 516 && mx <= 378 && my <= 627) // pixel
            {
                mazeselectorc = 0;
                maze = 0;
            }
            else if (mx >= 79 && my >= 310 && mx <= 323 && my <= 428) // nebula
            {
                mazeselectorc = 1;
                maze = 1;
            }
            else if (mx >= 126 && my >= 95 && mx <= 395 && my <= 217) // spectral
            {
                mazeselectorc = 2;
                maze = 2;
            }
            else if (mx >= 530 && my >= 51 && mx <= 745 && my <= 174) // psi
            {
                mazeselectorc = 3;
                maze = 3;
            }
            else if (mx >= 854 && my >= 66 && mx <= 1108 && my <= 189) // crack
            {
                mazeselectorc = 4;
                maze = 4;
            }
            else if (mx >= 887 && my >= 254 && mx <= 1126 && my <= 383) // echo
            {
                mazeselectorc = 5;
                maze = 5;
            }
            else if (mx >= 853 && my >= 460 && mx <= 1087 && my <= 591) // phantom
            {
                mazeselectorc = 6;
                maze = 6;
            }
            else if (mx >= 493 && my >= 527 && mx <= 735 && my <= 664)
            {
                mazeselectorc = 7;
                maze = 7;
            } // spiral
            else if (mx >= 29 && my >= 26 && mx <= 129 && my <= 63)
            {
                settings = 1;
                mazeselector = 0;
            }
        }
        else if (rules)
        {
            if (mx >= 1034 && my >= 69 && mx <= 1140 && my <= 117)
            {
                back = 1;
                rulescene = 199;
                //   iResumeTimer(0);
            }
        }
        else if (credits)
        {

            if ((mx >= 957 && mx <= 1182) && (my >= 36 && my <= 104))
            {
                credits = 0;
                mainmenu = 1;
                resumeimage = 1;
            }
        }
        else if (levelselect)
        {
            if ((mx >= 455 && mx <= 659) && (my >= 425 && my <= 492))
            {
                selected = 1;
                levelselect = 0;
                playingstart = 1;
                levelintro = 0;
                PacmanInitialCoordinate();
                pookieinitialcoordinate();
                foodCoordinateStore();
                foodcount();
                iResumeAll();
                if (soundOn)
                {
                    iPauseSound(sound4);
                    iPlaySound("sound/Tada.wav", 0, 100);
                }
            }
            else if ((mx <= 653 && mx >= 454) && (my <= 388 && my >= 331))
            {
                selected = 2;
                levelselect = 0;
                playingstart = 1;
                levelintro = 0;
                PacmanInitialCoordinate();
                pookieinitialcoordinate();
                foodCoordinateStore();
                foodcount();
                iResumeAll();
                if (soundOn)
                {
                    iPauseSound(sound4);
                    iPlaySound("sound/Tada.wav", 0, 100);
                }
            }
            else if ((mx >= 453 && my >= 229 && mx <= 655 && my <= 280))
            {
                selected = 3;
                levelselect = 0;
                playingstart = 1;
                levelintro = 0;
                PacmanInitialCoordinate();
                pookieinitialcoordinate();
                foodCoordinateStore();
                foodcount();
                iResumeAll();
                if (soundOn)
                {
                    iPauseSound(sound4);
                    iPlaySound("sound/Tada.wav", 0, 100);
                }
            }
            else if (mx <= 664 && my <= 180 && mx >= 444 && my >= 126)
            {
                selected = 4;
                levelselect = 0;
                playingstart = 1;
                levelintro = 0;
                PacmanInitialCoordinate();
                pookieinitialcoordinate();
                foodCoordinateStore();
                foodcount();
                iResumeAll();
                if (soundOn)
                {
                    iPauseSound(sound4);
                    iPlaySound("sound/Tada.wav", 0, 100);
                }
            }
        }
        else if (quit)
        {
            if ((mx >= 289 && mx <= 415) && (my >= 245 && my <= 299))
            {
                exitintro = 1;
                quit = 0;
            }
            else if ((mx >= 741 && mx <= 858) && (my >= 252 && my <= 302))
            {
                quitc = 0;
                quit = 0;
                mainmenu = 1;
                resumeimage = 1;
                if (soundOn)
                    iResumeSound(sound4);
            }
        }
        else if (pause)
        {
            if (mx >= 257 && my >= 420 && mx <= 698 && my <= 494)
            {
                pause = 0;
                mainmenu = 1;
                resumeimage = 1;
                storeGameStat(); // ✅
                iPauseAll();
                if (soundOn)
                    iResumeSound(sound4);
            }
            else if (mx >= 261 && my >= 299 && mx <= 534 && my <= 372)
            {
                playingstart = 1;
                pause = 0;
                iResumeAll();
            }
            else if (mx >= 257 && my >= 178 && mx <= 947 && my <= 245)
            {
                backgroundselector = 1;
                pause = 0;
            }
        }
        else if (playingstart)
        {
            if (mx >= 26 && my >= 599 && mx <= 177 && my <= 644)
            {
                pause = 1;
                playingstart = 0;
                storeGameStat();
                iPauseAll();
            }
        }
        else if (backgroundselector)
        {
            if (slbgimage == 1)
            {
                if (mx >= 121 && my >= 273 && mx <= 413 && my <= 501)
                {
                    bgimage = 0;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 2;
                }
                else if (mx >= 448 && my >= 323 && mx <= 760 && my <= 504)
                {
                    bgimage = 1;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 3;
                }
                else if (mx >= 795 && my >= 327 && mx <= 1092 && my <= 495)
                {
                    bgimage = 2;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 4;
                }
                else if (mx >= 252 && my >= 63 && mx <= 558 && my <= 238)
                {
                    bgimage = 3;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 5;
                }
                else if (mx >= 627 && my >= 79 && mx <= 934 && my <= 238)
                {
                    bgimage = 4;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 6;
                }
                else if (mx >= 29 && my >= 23 && mx <= 184 && my <= 73)
                {
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                }
            }
            else if (slbgimage == 2)
            {
                if (mx >= 121 && my >= 273 && mx <= 413 && my <= 501)
                {
                    bgimage = 5;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 1;
                }
                else if (mx >= 448 && my >= 323 && mx <= 760 && my <= 504)
                {
                    bgimage = 1;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 3;
                }
                else if (mx >= 795 && my >= 327 && mx <= 1092 && my <= 495)
                {
                    bgimage = 2;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 4;
                }
                else if (mx >= 252 && my >= 63 && mx <= 558 && my <= 238)
                {
                    bgimage = 3;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 5;
                }
                else if (mx >= 627 && my >= 79 && mx <= 934 && my <= 238)
                {
                    bgimage = 4;
                    backgroundselector = 0;
                    backgroundselectorc = 0;
                    slbgimage = 6;
                    pause = 1;
                }
                else if (mx >= 38 && my >= 26 && mx <= 119 && my <= 52)
                {
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                }
            }
            else if (slbgimage == 3)
            {
                if (mx >= 121 && my >= 273 && mx <= 413 && my <= 501)
                {
                    bgimage = 0;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 2;
                }
                else if (mx >= 448 && my >= 323 && mx <= 760 && my <= 504)
                {
                    bgimage = 5;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 1;
                }
                else if (mx >= 795 && my >= 327 && mx <= 1092 && my <= 495)
                {
                    bgimage = 2;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 4;
                }
                else if (mx >= 252 && my >= 63 && mx <= 558 && my <= 238)
                {
                    bgimage = 3;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 5;
                }
                else if (mx >= 627 && my >= 79 && mx <= 934 && my <= 238)
                {
                    bgimage = 4;
                    backgroundselector = 0;
                    backgroundselectorc = 0;
                    slbgimage = 6;
                    pause = 1;
                }
                else if (mx >= 38 && my >= 26 && mx <= 119 && my <= 52)
                {
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                }
            }
            else if (slbgimage == 4)
            {
                if (mx >= 121 && my >= 273 && mx <= 413 && my <= 501)
                {
                    bgimage = 0;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 2;
                }
                else if (mx >= 448 && my >= 323 && mx <= 760 && my <= 504)
                {
                    bgimage = 1;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 3;
                }
                else if (mx >= 795 && my >= 327 && mx <= 1092 && my <= 495)
                {
                    bgimage = 5;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 1;
                }
                else if (mx >= 252 && my >= 63 && mx <= 558 && my <= 238)
                {
                    bgimage = 3;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 5;
                }
                else if (mx >= 627 && my >= 79 && mx <= 934 && my <= 238)
                {
                    bgimage = 4;
                    backgroundselector = 0;
                    backgroundselectorc = 0;
                    slbgimage = 6;
                    pause = 1;
                }
                else if (mx >= 38 && my >= 26 && mx <= 119 && my <= 52)
                {
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                }
            }
            else if (slbgimage == 5)
            {
                if (mx >= 121 && my >= 273 && mx <= 413 && my <= 501)
                {
                    bgimage = 0;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 2;
                }
                else if (mx >= 448 && my >= 323 && mx <= 760 && my <= 504)
                {
                    bgimage = 1;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 3;
                }
                else if (mx >= 795 && my >= 327 && mx <= 1092 && my <= 495)
                {
                    bgimage = 2;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 4;
                }
                else if (mx >= 252 && my >= 63 && mx <= 558 && my <= 238)
                {
                    bgimage = 5;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 1;
                }
                else if (mx >= 627 && my >= 79 && mx <= 934 && my <= 238)
                {
                    bgimage = 4;
                    backgroundselector = 0;
                    backgroundselectorc = 0;
                    slbgimage = 6;
                    pause = 1;
                }
                else if (mx >= 38 && my >= 26 && mx <= 119 && my <= 52)
                {
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                }
            }
            else if (slbgimage == 6)
            {
                if (mx >= 121 && my >= 273 && mx <= 413 && my <= 501)
                {
                    bgimage = 0;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 2;
                }
                else if (mx >= 448 && my >= 323 && mx <= 760 && my <= 504)
                {
                    bgimage = 1;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 3;
                }
                else if (mx >= 795 && my >= 327 && mx <= 1092 && my <= 495)
                {
                    bgimage = 2;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 4;
                }
                else if (mx >= 252 && my >= 63 && mx <= 558 && my <= 238)
                {
                    bgimage = 3;
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                    slbgimage = 5;
                }
                else if (mx >= 627 && my >= 79 && mx <= 934 && my <= 238)
                {
                    bgimage = 5;
                    backgroundselector = 0;
                    backgroundselectorc = 0;
                    slbgimage = 1;
                    pause = 1;
                }
                else if (mx >= 38 && my >= 26 && mx <= 119 && my <= 52)
                {
                    backgroundselector = 0;
                    pause = 1;
                    backgroundselectorc = 0;
                }
            }
        }
    }
}

void foodCoordinateStore()
{
    /*  foodXcor and foodYcor are Used in this way :
        foodXcor[i][0]: stores the X-coordinate for the i-th food item.

        foodYcor[i]: stores the corresponding Y-coordinate for the i-th food item.

        foodXcor[i][1]: acts as a status flag, where:

        0 means uneaten food,

       -1 means eaten (i.e. don’t render),

       -2 (if used) marks special fruit or power pellets.
       */

    foodNum = 0; // Reset before storing new positions
    int i, j;

    if (selected == 1)
    {
        for (i = 0; i < 21; i++)
        {
            for (j = 0; j < 21; j++)
            {
                if (maze1[i][j] == 0)
                {
                    foodXcor[foodNum][0] = map1CoordinateX[i][j];
                    foodYcor[foodNum] = map1CoordinateY[i][j];
                    foodXcor[foodNum][1] = 0;
                    foodNum++;
                }
            }
        }
    }
    else if (selected == 2)
    {
        for (i = 0; i < 21; i++)
        {
            for (j = 0; j < 21; j++)
            {
                if (maze2[i][j] == 0)
                {
                    foodXcor[foodNum][0] = map2CoordinateX[i][j];
                    foodYcor[foodNum] = map2CoordinateY[i][j];
                    foodXcor[foodNum][1] = 0;
                    foodNum++;
                }
            }
        }
    }
    else if (selected == 3)
    {
        for (i = 0; i < 19; i++)
        {
            for (j = 0; j < 36; j++)
            {
                if (maze3[i][j] == 0)
                {
                    foodXcor[foodNum][0] = map3CoordinateX[i][j];
                    foodYcor[foodNum] = map3CoordinateY[i][j];
                    foodXcor[foodNum][1] = 0;
                    foodNum++;
                }
            }
        }
    }
    else if (selected == 4)
    {
        for (i = 0; i < 21; i++)
        {
            for (j = 0; j < 40; j++)
            {
                if (maze4[i][j] == 0)
                {
                    foodXcor[foodNum][0] = map4CoordinateX[i][j];
                    foodYcor[foodNum] = map4CoordinateY[i][j];
                    foodXcor[foodNum][1] = 0;
                    foodNum++;
                }
            }
        }
    }
}
void iResumeAll()
{
    for (int i = 1; i <= 5; i++)
    {
        iResumeTimer(i);
    }
}
void iPauseAll()
{
    for (int i = 1; i <= 5; i++)
    {
        iPauseTimer(i);
    }
}
void iKeyPress(unsigned char key)
{
    if (startintro)
    {
        if (key == 13)
        {
            startintro = 0;
            mainmenu = 1;
            resumeimage = 1;
        }
    }
    else if (congrats)
    {
        if (key == '\r')
        {
            congrats = 0;
            mainmenu = 1;
            times = 1;
            iStopSound(sound3);
            resumeimage = 1;
        }
    }
    else if (playgameintro)
    {

        if (typingName)
        {
            if (key == '\r' && len != 0) // ENTER pressed and name is not empty
            {
                namestr[len] = '\0';
                strcpy(playername, namestr);
                memset(namestr, 0, sizeof(namestr));
                len = 0;

                score = 0;
                converter(0, pacScore); // Reset score for display

                pacmanlife = 3;
                blueGhost = 0;
                for (int i = 0; i < 4; i++)
                {
                    pookie[i].blueOn = 0;
                }

                playgameintro = 0;
                levelselect = 1;
            }
            else if (key == 27) // ESC key
            {
                memset(namestr, 0, sizeof(namestr));
                len = 0;
                playgameintro = 0;
                mainmenu = 1;
            }
            else if (len && key == 8) // BACKSPACE
            {
                namestr[--len] = '\0';
                if (soundOn)
                    iPlaySound("sound/keypress.wav", 0, 80);
            }
            else if (len < 99) // Add new character if space available
            {
                if (key == ' ')
                {
                    namestr[len++] = '_';
                }
                else
                    namestr[len++] = key;
                if (soundOn)
                    iPlaySound("sound/keypress.wav", 0, 80);
                namestr[len] = '\0'; // Always null-terminate
            }
        }
    }
    if (playingstart)
    {
        if (key == 'a' || key == 'A')
        {

            if (!(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth))
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.upCount = 0;
                pac.leftCount = 1;
            }
            else
            {
                pac.smoothRight = 0;
                pac.smoothLeft = 1;
                pac.smoothDown = 0;
                pac.smoothUp = 0;
            }
        }
        if (key == 'd' || key == 'D')
        {
            if (!(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth))
            {
                pac.downCount = 0;
                pac.upCount = 0;
                pac.leftCount = 0;
                pac.rightCount = 1;
            }
            else
            {
                pac.smoothRight = 1;
                pac.smoothLeft = 0;
                pac.smoothDown = 0;
                pac.smoothUp = 0;
            }
        }
        if (key == 'c' || key == 'C')
        {
            if (!(pac.y % mazeCellWidth) && !(pac.x % mazeCellWidth))
            {
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 0;
                pac.downCount = 1;
            }
            else
            {
                pac.smoothRight = 0;
                pac.smoothLeft = 0;
                pac.smoothDown = 1;
                pac.smoothUp = 0;
            }
        }
        if (key == 'w' || key == 'W')
        {
            if (!(pac.y % mazeCellWidth) && !(pac.x % mazeCellWidth))
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 1;
            }
            else
            {
                pac.smoothRight = 0;
                pac.smoothLeft = 0;
                pac.smoothDown = 0;
                pac.smoothUp = 1;
            }
        }
    }
}
void bluetimecheck()
{
    if (selected == 3 || selected == 4)
    {
        if (blueGhost)
        {
            blueGhost--;
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                pookie[i].blueOn = 0;
            }
        }
    }
    if (selected == 1 || selected == 2)
    {
        if (blueGhost)
        {
            blueGhost--;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                pookie[i].blueOn = 0;
            }
        }
    }
}

void collisioncheck()
{
    if (playingstart)
    {
        if (selected == 1)
        {
            if (pac.smoothRight && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze1[cellY][cellX + 1])
            {
                pac.downCount = 0;
                pac.upCount = 0;
                pac.leftCount = 0;
                pac.rightCount = 1;
                pac.smoothRight = 0;
            }
            else if (pac.smoothLeft && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze1[cellY][cellX - 1])
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.upCount = 0;
                pac.leftCount = 1;
                pac.smoothLeft = 0;
            }
            else if (pac.smoothUp && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze1[cellY - 1][cellX])
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 1;
                pac.smoothUp = 0;
            }
            else if (pac.smoothDown && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze1[cellY + 1][cellX])
            {
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 0;
                pac.downCount = 1;
                pac.smoothDown = 0;
            }
        }
        if (selected == 2)
        {
            if (pac.smoothRight && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze2[cellY][cellX + 1])
            {
                pac.downCount = 0;
                pac.upCount = 0;
                pac.leftCount = 0;
                pac.rightCount = 1;
                pac.smoothRight = 0;
            }
            else if (pac.smoothLeft && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze2[cellY][cellX - 1])
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.upCount = 0;
                pac.leftCount = 1;
                pac.smoothLeft = 0;
            }
            else if (pac.smoothUp && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze2[cellY - 1][cellX])
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 1;
                pac.smoothUp = 0;
            }
            else if (pac.smoothDown && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze2[cellY + 1][cellX])
            {
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 0;
                pac.downCount = 1;
                pac.smoothDown = 0;
            }
        }
        if (selected == 3)
        {
            if (pac.smoothRight && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze3[cellY][cellX + 1])
            {
                pac.downCount = 0;
                pac.upCount = 0;
                pac.leftCount = 0;
                pac.rightCount = 1;
                pac.smoothRight = 0;
            }
            else if (pac.smoothLeft && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze3[cellY][cellX - 1])
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.upCount = 0;
                pac.leftCount = 1;
                pac.smoothLeft = 0;
            }
            else if (pac.smoothUp && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze3[cellY - 1][cellX])
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 1;
                pac.smoothUp = 0;
            }
            else if (pac.smoothDown && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze3[cellY + 1][cellX])
            {
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 0;
                pac.downCount = 1;
                pac.smoothDown = 0;
            }
        }
        if (selected == 4)
        {
            if (pac.smoothRight && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze4[cellY][cellX + 1])
            {
                pac.downCount = 0;
                pac.upCount = 0;
                pac.leftCount = 0;
                pac.rightCount = 1;
                pac.smoothRight = 0;
            }
            else if (pac.smoothLeft && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze4[cellY][cellX - 1])
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.upCount = 0;
                pac.leftCount = 1;
                pac.smoothLeft = 0;
            }
            else if (pac.smoothUp && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze4[cellY - 1][cellX])
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 1;
                pac.smoothUp = 0;
            }
            else if (pac.smoothDown && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze4[cellY + 1][cellX])
            {
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 0;
                pac.downCount = 1;
                pac.smoothDown = 0;
            }
        }
        foodhelp++;
        if (!(foodhelp % fruitTimeInterval) && foodXcor[*foodCor][1] != -2 && foodXcor[*foodCor][1] != 0)
        {
            foodCor = &fruitGen[rand() % (t - 1)]; // followed shuaib sir code
            foodXcor[*foodCor][1] = -2;
            randGen = rand() % 16;
        }
        if (totalfood == 0 && !times)
        {
            congrats = 1;
            playingstart = 0;
            storeGameStat();
            DataAnalysis();
            times = 1;
        }
        if (selected == 1 || selected == 2)
        {
            for (int i = 0; i <= foodNum; i++)
            {
                if ((pac.x == foodXcor[i][0]) && (pac.y == foodYcor[i]) && foodXcor[i][1] != -1)
                {
                    if (foodXcor[i][1] == -2)
                    {
                        if (randGen == 1 || randGen == 12)
                        {
                            pacmanlife++;
                            if (soundOn)
                                iPlaySound("sound/Treasure.wav", 0, 50);
                        }
                        else
                        {
                            if (soundOn)
                                iPlaySound("sound/pacman_eatfruit.wav", 0, 50);
                        }
                        foodXcor[i][1] = -1;
                        score += 1000;
                        converter(score, pacScore);
                    }
                    else
                    {
                        if (soundOn)
                            iPlaySound("sound/fright_firstloop.wav", 0, 50);
                        totalfood--;
                        printf("totalfood=%d ", totalfood);
                        foodXcor[i][1] = -1;
                        score += 10;
                        converter(score, pacScore);
                        fruitGen[t++] = i;
                        if (score > 1000)
                        {
                            chase = 1;
                            scatter = 0;
                        }
                        if (score > 6000)
                        {
                            chase = 0;
                            blast = 1;
                        }
                    }
                    if ((i == 0 || i == 18 || i == 149 || i == 104) && selected == 1)
                    {

                        blueScore = -1;
                        score += 40;
                        blueGhost = 10; // add foodXcor[i][1]!=-2
                        for (int i = 0; i < 4; i++)
                            pookie[i].blueOn = 1;
                    }
                    else if ((i == 0 || i == 18 || i == 165 || i == 156) && selected == 2)
                    {

                        blueScore = -1;
                        score += 40;
                        blueGhost = 10; // add foodXcor[i][1]!=-2
                        for (int i = 0; i < 4; i++)
                            pookie[i].blueOn = 1;
                    }
                }
            }
        }
        if (selected == 3 || selected == 4)
        {

            for (int i = 0; i <= foodNum; i++)
            {
                if ((pac.x == foodXcor[i][0]) && (pac.y == foodYcor[i]) && foodXcor[i][1] != -1)
                {
                    if (foodXcor[i][1] == -2)
                    {

                        if (randGen == 1 || randGen == 12)
                        {
                            pacmanlife++;
                            if (soundOn)
                                iPlaySound("sound/Treasure.wav", 0, 50);
                        }
                        else
                        {
                            if (soundOn)
                                iPlaySound("sound/pacman_eatfruit.wav", 0, 50);
                        }
                        foodXcor[i][1] = -1;
                        score += 1000;
                        converter(score, pacScore);
                    }
                    else
                    {
                        if (soundOn)
                            iPlaySound("sound/fright_firstloop.wav", 0, 50);
                        totalfood--;
                        printf("totalfood=%d ", totalfood);
                        foodXcor[i][1] = -1;
                        score += 10;
                        converter(score, pacScore);
                        fruitGen[t++] = i;
                        if (score > 3000)
                        {
                            chase = 1;
                            scatter = 0;
                        }
                        if (score > 9000)
                        {
                            chase = 0;
                            blast = 1;
                        }
                    }

                    if (selected == 3 && (i == 84 || i == 292 || i == 100 || i == 200))
                    {

                        blueScore = -1;
                        score += 40;
                        blueGhost = 10; // add foodXcor[i][1]!=-2
                        for (int i = 0; i < 6; i++)
                            pookie[i].blueOn = 1;
                    }
                    else if (selected == 4 && (i == 318 || i == 37 || i == 87 || i == 163 || i == 172 || i == 244 || i == 261 || i == 335 || i == 453 || i == 472))
                    {

                        blueScore = -1;
                        score += 40;
                        blueGhost = 10; // add foodXcor[i][1]!=-2
                        for (int i = 0; i < 6; i++)
                            pookie[i].blueOn = 1;
                    }
                }
            }
        }
        if (selected == 1 || selected == 2)
        {
            if (blueGhost)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (pookie[i].blueOn)
                    {
                        if (!(pookie[i].x % mazeCellWidth) && !(pookie[i].y % mazeCellWidth))
                        {
                            pookie[i].speed = 1;
                        }
                    }
                }
            }
            if (!blueGhost && (pookie[0].speed != diffSpeed || pookie[1].speed != diffSpeed || pookie[2].speed != diffSpeed || pookie[3].speed != diffSpeed))
            {
                for (int i = 0; i < 4; i++)
                {
                    if (!(pookie[i].x % mazeCellWidth) && !(pookie[i].y % mazeCellWidth))
                    {
                        pookie[i].speed = diffSpeed;
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                if (abs(pac.x - pookie[i].x) <= 20 && abs(pac.y - pookie[i].y) <= 20)
                {
                    if (!blueGhost || !pookie[i].blueOn)
                    {
                        pacdead = 1;
                        iPauseTimer(3);
                        iPauseTimer(2);
                    }
                    else
                    {
                        if (pookie[i].blueOn)
                        {
                            if (soundOn)
                                iPlaySound("sound/pacman_eatghost.wav", 0, 50);
                            blueScore++;
                            score += (100) * pow(3, blueScore);
                            converter(score, pacScore);
                            pookie[i].blueOn = 0;
                            if (selected == 1)
                            {
                                if (i == 0)
                                {
                                    pookie[0].cellX = 9; // Inky
                                    pookie[0].cellY = 9;
                                    pookie[0].x = 168 + (pookie[0].cellX) * mazeCellWidth;
                                    pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
                                    pookie[0].flagRight = 1;
                                    pookie[0].speed = diffSpeed;
                                }
                                else if (i == 1)
                                {
                                    pookie[1].cellX = 10; // Blinky
                                    pookie[1].cellY = 9;
                                    pookie[1].x = 168 + (pookie[1].cellX) * mazeCellWidth;
                                    pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
                                    pookie[1].flagUp = 1;
                                    pookie[1].speed = diffSpeed;
                                }
                                else if (i == 2)
                                {

                                    pookie[2].cellX = 10; // Pinky
                                    pookie[2].cellY = 9;
                                    pookie[2].x = 168 + (pookie[2].cellX) * mazeCellWidth;
                                    pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
                                    pookie[2].flagRight = 1;
                                    pookie[2].speed = diffSpeed;
                                }
                                else if (i == 3)
                                {
                                    pookie[3].cellX = 11; // Clyde
                                    pookie[3].cellY = 9;
                                    pookie[3].x = 168 + (pookie[3].cellX) * mazeCellWidth;
                                    pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
                                    pookie[3].flagRight = 1;
                                    pookie[3].speed = diffSpeed;
                                }
                            }
                            else if (selected == 2)
                            {
                                if (i == 0)
                                {
                                    pookie[0].cellX = 9; // Inky
                                    pookie[0].cellY = 8;
                                    pookie[0].x = 168 + (pookie[0].cellX) * mazeCellWidth;
                                    pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
                                    pookie[0].flagRight = 1;
                                    pookie[0].speed = diffSpeed;
                                }
                                else if (i == 1)
                                {
                                    pookie[1].cellX = 10; // Blinky
                                    pookie[1].cellY = 8;
                                    pookie[1].x = 168 + (pookie[1].cellX) * mazeCellWidth;
                                    pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
                                    pookie[1].flagUp = 1;
                                    pookie[1].speed = diffSpeed;
                                }
                                else if (i == 2)
                                {
                                    pookie[2].cellX = 10; // Pinky
                                    pookie[2].cellY = 8;
                                    pookie[2].x = 168 + (pookie[2].cellX) * mazeCellWidth;
                                    pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
                                    pookie[2].flagRight = 1;
                                    pookie[2].speed = diffSpeed;
                                }
                                else if (i == 3)
                                {
                                    pookie[3].cellX = 11; // Clyde
                                    pookie[3].cellY = 8;
                                    pookie[3].x = 168 + (pookie[3].cellX) * mazeCellWidth;
                                    pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
                                    pookie[3].flagRight = 1;
                                    pookie[3].speed = diffSpeed;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (selected == 3 || selected == 4)
        {
            if (blueGhost)
            {
                for (int i = 0; i < 6; i++)
                {
                    if (pookie[i].blueOn)
                    {
                        if (!(pookie[i].x % mazeCellWidth) && !(pookie[i].y % mazeCellWidth))
                        {
                            pookie[i].speed = 1;
                        }
                    }
                }
            }
            if (!blueGhost && (pookie[0].speed != diffSpeed || pookie[1].speed != diffSpeed || pookie[2].speed != diffSpeed || pookie[3].speed != diffSpeed || pookie[4].speed != diffSpeed || pookie[5].speed != diffSpeed))
            {
                for (int i = 0; i < 6; i++)
                {
                    if (!(pookie[i].x % mazeCellWidth) && !(pookie[i].y % mazeCellWidth))
                    {
                        pookie[i].speed = diffSpeed;
                    }
                }
            }
            for (int i = 0; i < 6; i++)
            {
                if (abs(pac.x - pookie[i].x) <= 20 && abs(pac.y - pookie[i].y) <= 20)
                {
                    if (!blueGhost || !pookie[i].blueOn)
                    {

                        pacdead = 1;
                        iPauseTimer(3);
                        iPauseTimer(2);
                    }
                    else
                    {
                        if (pookie[i].blueOn)
                        {
                            if (soundOn)
                                iPlaySound("sound/pacman_eatghost.wav", 0, 50);
                            blueScore++;
                            score += (100) * pow(3, blueScore);
                            converter(score, pacScore);
                            pookie[i].blueOn = 0;

                            if (selected == 3)
                            {
                                if (i == 0)
                                {
                                    pookie[0].cellX = 15; // Inky
                                    pookie[0].cellY = 14;
                                    pookie[0].x = 72 + (pookie[0].cellX) * mazeCellWidth;
                                    pookie[0].y = 48 + (18 - pookie[0].cellY) * mazeCellWidth;
                                    pookie[0].flagRight = 1;
                                    pookie[0].speed = diffSpeed;
                                }
                                else if (i == 1)
                                {

                                    pookie[1].cellX = 16; // Blinky
                                    pookie[1].cellY = 14;
                                    pookie[1].x = 72 + (pookie[1].cellX) * mazeCellWidth;
                                    pookie[1].y = 48 + (18 - pookie[1].cellY) * mazeCellWidth;
                                    pookie[1].flagUp = 1;
                                    pookie[1].speed = diffSpeed;
                                }
                                else if (i == 2)
                                {
                                    pookie[2].cellX = 17; // Pinky
                                    pookie[2].cellY = 14;
                                    pookie[2].x = 72 + (pookie[2].cellX) * mazeCellWidth;
                                    pookie[2].y = 48 + (18 - pookie[2].cellY) * mazeCellWidth;
                                    pookie[2].flagRight = 1;
                                    pookie[2].speed = diffSpeed;
                                }
                                else if (i == 3)
                                {

                                    pookie[3].cellX = 18; // Clyde
                                    pookie[3].cellY = 14;
                                    pookie[3].x = 72 + (pookie[3].cellX) * mazeCellWidth;
                                    pookie[3].y = 48 + (18 - pookie[3].cellY) * mazeCellWidth;
                                    pookie[3].flagRight = 1;
                                    pookie[3].speed = diffSpeed;
                                }
                                else if (i == 4)
                                {
                                    pookie[4].cellX = 19; // donky
                                    pookie[4].cellY = 14;
                                    pookie[4].x = 72 + (pookie[4].cellX) * mazeCellWidth;
                                    pookie[4].y = 48 + (18 - pookie[4].cellY) * mazeCellWidth;
                                    pookie[4].flagRight = 1;
                                    pookie[4].speed = diffSpeed;
                                }
                                else if (i == 5)
                                {
                                    pookie[5].cellX = 18; // rinky
                                    pookie[5].cellY = 14;
                                    pookie[5].x = 72 + (pookie[5].cellX) * mazeCellWidth;
                                    pookie[5].y = 48 + (18 - pookie[5].cellY) * mazeCellWidth;
                                    pookie[5].flagRight = 1;
                                    pookie[5].speed = diffSpeed;
                                }
                            }
                            else if (selected == 4)
                            {
                                if (i == 0)
                                {
                                    pookie[0].cellX = 1; // Inky
                                    pookie[0].cellY = 19;
                                    pookie[0].x = 72 + (pookie[0].cellX) * mazeCellWidth;
                                    pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
                                    pookie[0].flagRight = 1;
                                    pookie[0].speed = diffSpeed;
                                }
                                else if (i == 1)
                                {
                                    pookie[1].cellX = 12; // Blinky
                                    pookie[1].cellY = 19;
                                    pookie[1].x = 72 + (pookie[1].cellX) * mazeCellWidth;
                                    pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
                                    pookie[1].flagUp = 1;
                                    pookie[1].speed = diffSpeed;
                                }
                                else if (i == 2)
                                {
                                    pookie[2].cellX = 20; // Pinky
                                    pookie[2].cellY = 19;
                                    pookie[2].x = 72 + (pookie[2].cellX) * mazeCellWidth;
                                    pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
                                    pookie[2].flagRight = 1;
                                    pookie[2].speed = diffSpeed;
                                }
                                else if (i == 3)
                                {
                                    pookie[3].cellX = 30; // Clyde
                                    pookie[3].cellY = 19;
                                    pookie[3].x = 72 + (pookie[3].cellX) * mazeCellWidth;
                                    pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
                                    pookie[3].flagRight = 1;
                                    pookie[3].speed = diffSpeed;
                                }
                                else if (i == 4)
                                {
                                    pookie[4].cellX = 25; // donkey
                                    pookie[4].cellY = 19;
                                    pookie[4].x = 72 + (pookie[4].cellX) * mazeCellWidth;
                                    pookie[4].y = 48 + (20 - pookie[4].cellY) * mazeCellWidth;
                                    pookie[4].flagRight = 1;
                                    pookie[4].speed = diffSpeed;
                                }
                                else if (i == 5)
                                {
                                    pookie[5].cellX = 38; // rinky
                                    pookie[5].cellY = 19;
                                    pookie[5].x = 72 + (pookie[5].cellX) * mazeCellWidth;
                                    pookie[5].y = 48 + (20 - pookie[5].cellY) * mazeCellWidth;
                                    pookie[5].flagRight = 1;
                                    pookie[5].speed = diffSpeed;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void iSpecialKeyPress(unsigned char key)
{
    if (playingstart)
    {
        if (key == GLUT_KEY_LEFT)
        {

            if (!(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth))
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.upCount = 0;
                pac.leftCount = 1;
            }
            else
            {
                pac.smoothRight = 0;
                pac.smoothLeft = 1;
                pac.smoothDown = 0;
                pac.smoothUp = 0;
            }
        }
        if (key == GLUT_KEY_RIGHT)
        {
            if (!(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth))
            {
                pac.downCount = 0;
                pac.upCount = 0;
                pac.leftCount = 0;
                pac.rightCount = 1;
            }
            else
            {
                pac.smoothRight = 1;
                pac.smoothLeft = 0;
                pac.smoothDown = 0;
                pac.smoothUp = 0;
            }
        }
        if (key == GLUT_KEY_DOWN)
        {
            if (!(pac.y % mazeCellWidth) && !(pac.x % mazeCellWidth))
            {
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 0;
                pac.downCount = 1;
            }
            else
            {
                pac.smoothRight = 0;
                pac.smoothLeft = 0;
                pac.smoothDown = 1;
                pac.smoothUp = 0;
            }
        }
        if (key == GLUT_KEY_UP)
        {
            if (!(pac.y % mazeCellWidth) && !(pac.x % mazeCellWidth))
            {
                pac.downCount = 0;
                pac.rightCount = 0;
                pac.leftCount = 0;
                pac.upCount = 1;
            }
            else
            {
                pac.smoothRight = 0;
                pac.smoothLeft = 0;
                pac.smoothDown = 0;
                pac.smoothUp = 1;
            }
        }
    }
}
void PacmanInitialCoordinate()
{
    if (selected == 1 || selected == 2)
    {
        cellX = 9;
        cellY = 19;
        pac.x = 168 + (cellX)*mazeCellWidth;
        pac.y = 48 + (20 - cellY) * mazeCellWidth;

        pac.downCount = 0;
        pac.rightCount = 0;
        pac.upCount = 0;
        pac.leftCount = 0;
    }
    else if (selected == 3)
    {
        cellX = 1;
        cellY = 1;
        pac.x = 72 + (cellX)*mazeCellWidth;
        pac.y = 48 + (18 - cellY) * mazeCellWidth;

        pac.downCount = 0;
        pac.rightCount = 0;
        pac.upCount = 0;
        pac.leftCount = 0;
    }
    else if (selected == 4)
    {
        cellX = 1;
        cellY = 1;
        pac.x = 72 + (cellX)*mazeCellWidth;
        pac.y = 48 + (20 - cellY) * mazeCellWidth;

        pac.downCount = 0;
        pac.rightCount = 0;
        pac.upCount = 0;
        pac.leftCount = 0;
    }
}
void pookieinitialcoordinate()
{
    if (selected == 1)
    {
        pookie[0].cellX = 9; // Inky
        pookie[0].cellY = 9;
        pookie[0].x = 168 + (pookie[0].cellX) * mazeCellWidth;
        pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
        pookie[0].flagRight = 1;
        pookie[0].speed = diffSpeed;

        pookie[1].cellX = 10; // Blinky
        pookie[1].cellY = 9;
        pookie[1].x = 168 + (pookie[1].cellX) * mazeCellWidth;
        pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
        pookie[1].flagUp = 1;
        pookie[1].speed = diffSpeed;

        pookie[2].cellX = 10; // Pinky
        pookie[2].cellY = 9;
        pookie[2].x = 168 + (pookie[2].cellX) * mazeCellWidth;
        pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
        pookie[2].flagRight = 1;
        pookie[2].speed = diffSpeed;

        pookie[3].cellX = 11; // Clyde
        pookie[3].cellY = 9;
        pookie[3].x = 168 + (pookie[3].cellX) * mazeCellWidth;
        pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
        pookie[3].flagRight = 1;
        pookie[3].speed = diffSpeed;
    }
    else if (selected == 2)
    {
        pookie[0].cellX = 9; // Inky
        pookie[0].cellY = 8;
        pookie[0].x = 168 + (pookie[0].cellX) * mazeCellWidth;
        pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
        pookie[0].flagRight = 1;
        pookie[0].speed = diffSpeed;

        pookie[1].cellX = 10; // Blinky
        pookie[1].cellY = 8;
        pookie[1].x = 168 + (pookie[1].cellX) * mazeCellWidth;
        pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
        pookie[1].flagUp = 1;
        pookie[1].speed = diffSpeed;

        pookie[2].cellX = 10; // Pinky
        pookie[2].cellY = 8;
        pookie[2].x = 168 + (pookie[2].cellX) * mazeCellWidth;
        pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
        pookie[2].flagRight = 1;
        pookie[2].speed = diffSpeed;

        pookie[3].cellX = 11; // Clyde
        pookie[3].cellY = 8;
        pookie[3].x = 168 + (pookie[3].cellX) * mazeCellWidth;
        pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
        pookie[3].flagRight = 1;
        pookie[3].speed = diffSpeed;
    }
    else if (selected == 3)
    {
        pookie[0].cellX = 15; // Inky
        pookie[0].cellY = 14;
        pookie[0].x = 72 + (pookie[0].cellX) * mazeCellWidth;
        pookie[0].y = 48 + (18 - pookie[0].cellY) * mazeCellWidth;
        pookie[0].flagRight = 1;
        pookie[0].speed = diffSpeed;

        pookie[1].cellX = 16; // Blinky
        pookie[1].cellY = 14;
        pookie[1].x = 72 + (pookie[1].cellX) * mazeCellWidth;
        pookie[1].y = 48 + (18 - pookie[1].cellY) * mazeCellWidth;
        pookie[1].flagUp = 1;
        pookie[1].speed = diffSpeed;

        pookie[2].cellX = 17; // Pinky
        pookie[2].cellY = 14;
        pookie[2].x = 72 + (pookie[2].cellX) * mazeCellWidth;
        pookie[2].y = 48 + (18 - pookie[2].cellY) * mazeCellWidth;
        pookie[2].flagRight = 1;
        pookie[2].speed = diffSpeed;

        pookie[3].cellX = 18; // Clyde
        pookie[3].cellY = 14;
        pookie[3].x = 72 + (pookie[3].cellX) * mazeCellWidth;
        pookie[3].y = 48 + (18 - pookie[3].cellY) * mazeCellWidth;
        pookie[3].flagRight = 1;
        pookie[3].speed = diffSpeed;

        pookie[4].cellX = 19; // donky
        pookie[4].cellY = 14;
        pookie[4].x = 72 + (pookie[4].cellX) * mazeCellWidth;
        pookie[4].y = 48 + (18 - pookie[4].cellY) * mazeCellWidth;
        pookie[4].flagRight = 1;
        pookie[4].speed = diffSpeed;

        pookie[5].cellX = 18; // rinky
        pookie[5].cellY = 14;
        pookie[5].x = 72 + (pookie[5].cellX) * mazeCellWidth;
        pookie[5].y = 48 + (18 - pookie[5].cellY) * mazeCellWidth;
        pookie[5].flagRight = 1;
        pookie[5].speed = diffSpeed;
    }
    else if (selected == 4)
    {
        pookie[0].cellX = 1; // Inky
        pookie[0].cellY = 19;
        pookie[0].x = 72 + (pookie[0].cellX) * mazeCellWidth;
        pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
        pookie[0].flagRight = 1;
        pookie[0].speed = diffSpeed;

        pookie[1].cellX = 12; // Blinky
        pookie[1].cellY = 19;
        pookie[1].x = 72 + (pookie[1].cellX) * mazeCellWidth;
        pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
        pookie[1].flagUp = 1;
        pookie[1].speed = diffSpeed;

        pookie[2].cellX = 20; // Pinky
        pookie[2].cellY = 19;
        pookie[2].x = 72 + (pookie[2].cellX) * mazeCellWidth;
        pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
        pookie[2].flagRight = 1;
        pookie[2].speed = diffSpeed;

        pookie[3].cellX = 30; // Clyde
        pookie[3].cellY = 19;
        pookie[3].x = 72 + (pookie[3].cellX) * mazeCellWidth;
        pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
        pookie[3].flagRight = 1;
        pookie[3].speed = diffSpeed;

        pookie[4].cellX = 25; // donkey
        pookie[4].cellY = 19;
        pookie[4].x = 72 + (pookie[4].cellX) * mazeCellWidth;
        pookie[4].y = 48 + (20 - pookie[4].cellY) * mazeCellWidth;
        pookie[4].flagRight = 1;
        pookie[4].speed = diffSpeed;

        pookie[5].cellX = 38; // rinky
        pookie[5].cellY = 19;
        pookie[5].x = 72 + (pookie[5].cellX) * mazeCellWidth;
        pookie[5].y = 48 + (20 - pookie[5].cellY) * mazeCellWidth;
        pookie[5].flagRight = 1;
        pookie[5].speed = diffSpeed;
    }
}
void introchange()
{
    if (startintro)
    {
        intro++;
        if (intro > 114)
        {
            intro = 0;
            startintro = 0;
            mainmenu = 1;
            resumeimage = 1;
        }
    }
}
void scoreshow()
{
    if (congrats)
    {
        congratsc++;
        if (congratsc > 99)
        {
            congratsc = 0;
            congrats = 0;
            playingstart = 0;
            storeGameStat();
            mainmenu = 1;
            times = 0;
            iStopSound(sound3);
            if (soundOn)
                iPauseSound(sound4);
            // selected = (selected + 1) % 4;
            //    PacmanInitialCoordinate();
            //  pookieinitialcoordinate();
            //  foodCoordinateStore();
            //  foodcount();
        }
    }
}
void resumesequence()
{
    if (resumeimage)
    {
        resumec++;
        if (resumec > 249)
        {
            resumeimage = 0;
            resumec = 0;
        }
    }
    if (congrats)
    {
        congratsc++;
        if (congratsc > 99)
        {
            congratsc = 0;
            congrats = 0;
            playingstart = 0;
            storeGameStat();
            mainmenu = 1;
            resumeimage = 1;
            times = 0;
            iStopSound(sound3);
            if (soundOn)
                iPauseSound(sound4);
            // selected = (selected + 1) % 4;
            //    PacmanInitialCoordinate();
            //  pookieinitialcoordinate();
            //  foodCoordinateStore();
            //  foodcount();
        }
    }
    if (levelselect)
    {
        levelintro++;
        if (levelintro > 99)
        {
            levelintro = 0;
            //  iPauseTimer(0);
        }
    }
    if (rules && !back)
    {
        if (rulescene == 0)
            iPlaySound("sound/slide.wav", 0, 70);
        rulescene++;
        if (rulescene > 199)
        {
            rulescene = 199;
            iPauseTimer(t);
        }
    }
    if (rules && back)
    {
        rulescene++;
        if (rulescene == 201)
            iPlaySound("sound/slide.wav", 0, 70);
        if (rulescene > 249)
        {
            rules = 0;
            back = 0;
            mainmenu = 1;
            iResumeTimer(t);
            resumeimage = 1;
            rulescene = 0;
            if (soundOn)
                iResumeSound(sound4);
        }
    }
}

void exitSequence()
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
void background()
{
    if (backgroundselector)
    {
        backgroundselectorc++;
        if (backgroundselectorc > 99)
        {
            backgroundselectorc = 99;
        }
    }
}
void levelShow()
{
    if (levelselect)
    {
        levelintro++;
        if (levelintro > 99)
        {
            levelintro = 0;
        }
    }
}
void loading()
{
    if (load)
    {
        loadc++;
        if (loadc > 199)
        {
            loadc = 0;
            load = 0;
            resumeGameSession();
        }
    }
}
void deathScene()
{
    if (pacdead)
    {
        if (deadSceneCount == 0)
        {
            if (soundOn)
                sound2 = iPlaySound("sound/pacman_death.wav", 0, 50);
        }
        deadSceneCount++;
        if (deadSceneCount > 10)
        {
            // if (soundOn)
            // sound2 = iPlaySound("sound/pacman_death.wav", 0, 50);
            deadSceneCount = 0;
            pacdead = 0;
            pacmanlife--;
            PacmanInitialCoordinate();
            pookieinitialcoordinate();
            blueGhost = 0;
            pookie[0].blueOn = 0;
            pookie[1].blueOn = 0;
            pookie[2].blueOn = 0;
            pookie[3].blueOn = 0;
            Sleep(800);
            if (pacmanlife == 0)
            {
                chase = 0;
                scatter = 1;
                DataAnalysis();
                congrats = 1;
                iStopSound(sound2);
                if (soundOn)
                    sound3 = iPlaySound("sound/gameover.wav", 0, 50);
            }

            iResumeTimer(3);
            iResumeTimer(2);
        }
    }
}
void RulesShow() // Because of the iSetTimer limitation ( Error: Maximum number of timers reached. ) this function is operated in void resumesequence() function
{
    if (rules && !back)
    {
        if (rulescene == 0)
            iPlaySound("sound/slide.wav", 0, 70);
        rulescene++;
        if (rulescene > 199)
        {
            rulescene = 199;
            iPauseTimer(0);
        }
    }
    if (rules && back)
    {
        rulescene++;
        if (rulescene == 201)
            iPlaySound("sound/slide.wav", 0, 70);
        if (rulescene > 249)
        {
            rules = 0;
            back = 0;
            mainmenu = 1;
            rulescene = 0;
            if (soundOn)
                iResumeSound(sound4);
        }
    }
}
void DataAnalysis()
{

    FILE *input;
    char ch;
    line = 0;
    if (score != 0)
    {
        // Sub write
        input = fopen("Score.txt", "a");
        fprintf(input, "%s %d\n", playername, score);
        fclose(input);
    }

    input = fopen("Score.txt", "r");
    while (fscanf(input, "%c", &ch) == 1)
    {
        if (ch == '\n')
            line++;
    }
    fclose(input);
    // Store data
    input = fopen("Score.txt", "r");
    name = (char **)malloc(sizeof(char *) * line);
    point = (int *)malloc(sizeof(int) * line);
    for (int i = 0; i < line; i++)
    {
        name[i] = (char *)malloc(sizeof(char) * 20);
        fscanf(input, " %s %d", name[i], &point[i]);
    }
    fclose(input);
    // Sort data
    for (int i = 0; i < line; i++)
    {
        for (int j = i; j < line; j++)
        {
            if (point[i] < point[j])
            {
                int t = point[i];
                point[i] = point[j];
                point[j] = t;
                char *p = name[i];
                name[i] = name[j];
                name[j] = p;
            }
        }
    }
    // Write Data
    input = fopen("highScore.txt", "w");
    for (int i = 0; i < line; i++)
    {
        fprintf(input, "%s %d\n", name[i], point[i]);
    }
    fclose(input);
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    DataAnalysis();
    corrdinatestore1();
    corrdinatestore2();
    corrdinatestore3();
    corrdinatestore4();
    if (soundOn)
    {
        sound1 = iPlaySound("sound/Music_startSound.wav", 0, 50);
        sound4 = iPlaySound("sound/Dyson Sphere.wav", 0, 20);
    }
    iSetTimer(20, collisioncheck);
    iSetTimer(1300, bluetimecheck);
    iSetTimer(30, pookiemovement);
    iSetTimer(30, pacmanmovement);
    iSetTimer(20, introchange);
    iSetTimer(120, deathScene);
    // iSetTimer(20, scoreshow);
    int t = iSetTimer(30, resumesequence);
    iSetTimer(20, exitSequence);
    // iSetTimer(30, levelShow);
    //  iSetTimer(30, RulesShow);    Error: Maximum number of timers reached.
    iSetTimer(20, background);
    iSetTimer(30, loading);

    iWindowedMode(1200, 675, "PACMAN");
    iStartMainLoop();
    printf("Exiting main loop...\n");
    return 0;
}