
#include "iGraphics.h"
#include <stdlib.h>

void pacinitialcord();
void pookieinitialcoordinate();
char *converter(int num, char *str);
void foodCoordinateStore();
int calcDist(int x1, int y1, int x2, int y2);
void drawFoodAndPowerPellet();
void pookiemovement();
void pacmanmovement();
void iResumeAll();
void iPauseAll();
void bluetimecheck();
void DataAnalysis();
void foodcount();
void pacinitialcord();
void pookieinitialcoordinate();
void collisioncheck();

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
int bgimage = 0;
int mazeX;
int mazeY;
int line = 0;

int maze = 0;
int intro = 0;
int exitintroimage = 0;
int ratul = 0;
char namestr[100];
char playername[100];
int *point;
char **name;
int len;
bool typingName = false;
int score;
char pacScore[20] = "00";
char temp[20];

int pacmanlife = 3;
bool pacdead = false;
int pacspeed = 3;
int deadSceneCount = 0;
bool deadsound = false;
int blueGhost;
int diffSpeed = 2;
int foodNum = 5;
bool scatter = true;
bool chase;

bool soundOn = true;
bool startintro = true;
bool specialthanks;
bool exitintro;
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
bool pause;
bool backgroundselector;
bool deadscene;
bool congrats;
bool blast;

typedef struct
{
    int upInd, downInd, leftInd, rightInd;
    int x;
    int y;
    bool upCount, downCount, leftCount, rightCount;
    bool smoothRight, smoothLeft, smoothUp, smoothDown;
    int right, left, up, down;
} move;

typedef struct
{
    int upInd, downInd, leftInd, rightInd;
    int x;
    int y;
    int cellX, cellY;
    bool flagRight, flagLeft, flagUp, flagDown;
    int left, right, up, down;
    int speed;
    bool blueOn;
    int dist1, dist2;
} ghost;

ghost pookie[4];
move pac;

char introimage[115][50] = {"introimage/introimage (1).jpg", "introimage/introimage (2).jpg", "introimage/introimage (3).jpg", "introimage/introimage (4).jpg", "introimage/introimage (5).jpg", "introimage/introimage (6).jpg", "introimage/introimage (7).jpg", "introimage/introimage (8).jpg", "introimage/introimage (9).jpg", "introimage/introimage (10).jpg", "introimage/introimage (11).jpg", "introimage/introimage (12).jpg", "introimage/introimage (13).jpg", "introimage/introimage (14).jpg", "introimage/introimage (15).jpg", "introimage/introimage (16).jpg", "introimage/introimage (17).jpg", "introimage/introimage (18).jpg", "introimage/introimage (20).jpg", "introimage/introimage (20).jpg", "introimage/introimage (21).jpg", "introimage/introimage (22).jpg", "introimage/introimage (23).jpg", "introimage/introimage (24).jpg", "introimage/introimage (25).jpg", "introimage/introimage (26).jpg", "introimage/introimage (27).jpg", "introimage/introimage (28).jpg", "introimage/introimage (29).jpg", "introimage/introimage (30).jpg", "introimage/introimage (31).jpg", "introimage/introimage (32).jpg", "introimage/introimage (33).jpg", "introimage/introimage (34).jpg", "introimage/introimage (35).jpg", "introimage/introimage (36).jpg", "introimage/introimage (37).jpg", "introimage/introimage (38).jpg", "introimage/introimage (39).jpg", "introimage/introimage (40).jpg", "introimage/introimage (41).jpg", "introimage/introimage (42).jpg", "introimage/introimage (43).jpg", "introimage/introimage (44).jpg", "introimage/introimage (45).jpg", "introimage/introimage (46).jpg", "introimage/introimage (47).jpg", "introimage/introimage (48).jpg", "introimage/introimage (49).jpg", "introimage/introimage (50).jpg", "introimage/introimage (51).jpg", "introimage/introimage (52).jpg", "introimage/introimage (53).jpg", "introimage/introimage (54).jpg", "introimage/introimage (55).jpg", "introimage/introimage (56).jpg", "introimage/introimage (57).jpg", "introimage/introimage (58).jpg", "introimage/introimage (59).jpg", "introimage/introimage (60).jpg", "introimage/introimage (61).jpg", "introimage/introimage (62).jpg", "introimage/introimage (63).jpg", "introimage/introimage (64).jpg", "introimage/introimage (65).jpg", "introimage/introimage (66).jpg", "introimage/introimage (67).jpg", "introimage/introimage (68).jpg", "introimage/introimage (69).jpg", "introimage/introimage (70).jpg", "introimage/introimage (71).jpg", "introimage/introimage (72).jpg", "introimage/introimage (73).jpg", "introimage/introimage (74).jpg", "introimage/introimage (75).jpg", "introimage/introimage (76).jpg", "introimage/introimage (77).jpg", "introimage/introimage (78).jpg", "introimage/introimage (79).jpg", "introimage/introimage (80).jpg", "introimage/introimage (81).jpg", "introimage/introimage (82).jpg", "introimage/introimage (83).jpg", "introimage/introimage (84).jpg", "introimage/introimage (85).jpg", "introimage/introimage (86).jpg", "introimage/introimage (87).jpg", "introimage/introimage (88).jpg", "introimage/introimage (89).jpg", "introimage/introimage (90).jpg", "introimage/introimage (91).jpg", "introimage/introimage (92).jpg", "introimage/introimage (93).jpg", "introimage/introimage (94).jpg", "introimage/introimage (95).jpg", "introimage/introimage (96).jpg", "introimage/introimage (97).jpg", "introimage/introimage (98).jpg", "introimage/introimage (99).jpg", "introimage/introimage (100).jpg", "introimage/introimage (101).jpg", "introimage/introimage (102).jpg", "introimage/introimage (103).jpg", "introimage/introimage (104).jpg", "introimage/introimage (105).jpg", "introimage/introimage (106).jpg", "introimage/introimage (107).jpg", "introimage/introimage (108).jpg", "introimage/introimage (109).jpg", "introimage/introimage (110).jpg", "introimage/introimage (111).jpg", "introimage/introimage (112).jpg", "introimage/introimage (113).jpg", "introimage/introimage (114).jpg", "introimage/introimage (115).jpg"};
char mazeselectorimage[8][60] = {"mazeSelectorImage/pixel.PNG", "mazeSelectorImage/nebula.PNG", "mazeSelectorImage/spectral.PNG", "mazeSelectorImage/psi.PNG", "mazeSelectorImage/crack.PNG", "mazeSelectorImage/echo.PNG", "mazeSelectorImage/phantom.PNG", "mazeSelectorImage/spiral.PNG"};
char menuimage[9][50] = {"menu image/PACMAN.png", "menu image/pacman1.png", "menu image/pacman2.png", "menu image/pacman3.png", "menu image/pacman4.png", "menu image/pacman5.png", "menu image/pacman6.png", "menu image/pacman7.png", "menu image/pacman8.png"};
char settingsimage[8][50] = {"settingsimage/settings.png", "settingsimage/settings1.png", "settingsimage/settings2.png", "settingsimage/settings3.png", "settingsimage/settings4.png", "settingsimage/settings5.png", "settingsimage/settings6.png", "settingsimage/settings7.png"};
char highscoreimage[2][50] = {"highscoreimage/highscore (2).png", "highscoreimage/highscore (1).png"};
char creditimage[2][50] = {"creditsimage/CREDITS.png", "creditsimage/credits1.png"};
char rulesimage[2][50] = {"rules/RULES.png", "rules/rules1.png"};
char levelselectimage[100][50] = {"level/level (1).jpg", "level/level (2).jpg", "level/level (3).jpg", "level/level (4).jpg", "level/level (5).jpg", "level/level (6).jpg", "level/level (7).jpg", "level/level (8).jpg", "level/level (9).jpg", "level/level (10).jpg", "level/level (11).jpg", "level/level (12).jpg", "level/level (13).jpg", "level/level (14).jpg", "level/level (15).jpg", "level/level (16).jpg", "level/level (17).jpg", "level/level (18).jpg", "level/level (20).jpg", "level/level (20).jpg", "level/level (21).jpg", "level/level (22).jpg", "level/level (23).jpg", "level/level (24).jpg", "level/level (25).jpg", "level/level (26).jpg", "level/level (27).jpg", "level/level (28).jpg", "level/level (29).jpg", "level/level (30).jpg", "level/level (31).jpg", "level/level (32).jpg", "level/level (33).jpg", "level/level (34).jpg", "level/level (35).jpg", "level/level (36).jpg", "level/level (37).jpg", "level/level (38).jpg", "level/level (39).jpg", "level/level (40).jpg", "level/level (41).jpg", "level/level (42).jpg", "level/level (43).jpg", "level/level (44).jpg", "level/level (45).jpg", "level/level (46).jpg", "level/level (47).jpg", "level/level (48).jpg", "level/level (49).jpg", "level/level (50).jpg", "level/level (51).jpg", "level/level (52).jpg", "level/level (53).jpg", "level/level (54).jpg", "level/level (55).jpg", "level/level (56).jpg", "level/level (57).jpg", "level/level (58).jpg", "level/level (59).jpg", "level/level (60).jpg", "level/level (61).jpg", "level/level (62).jpg", "level/level (63).jpg", "level/level (64).jpg", "level/level (65).jpg", "level/level (66).jpg", "level/level (67).jpg", "level/level (68).jpg", "level/level (69).jpg", "level/level (70).jpg", "level/level (71).jpg", "level/level (72).jpg", "level/level (73).jpg", "level/level (74).jpg", "level/level (75).jpg", "level/level (76).jpg", "level/level (77).jpg", "level/level (78).jpg", "level/level (79).jpg", "level/level (80).jpg", "level/level (81).jpg", "level/level (82).jpg", "level/level (83).jpg", "level/level (84).jpg", "level/level (85).jpg", "level/level (86).jpg", "level/level (87).jpg", "level/level (88).jpg", "level/level (89).jpg", "level/level (90).jpg", "level/level (91).jpg", "level/level (92).jpg", "level/level (93).jpg", "level/level (94).jpg", "level/level (95).jpg", "level/level (96).jpg", "level/level (97).jpg", "level/level (98).jpg", "level/level (99).jpg", "level/level (100).jpg"};
char quitimage[3][50] = {"exitimage/exitimage.png", "exitimage/exitimage1.png", "exitimage/exitimage2.png"};
char difficultyimage[5][50] = {"difficultyimage/Difficulty1.png", "difficultyimage/Difficulty2.png", "difficultyimage/Difficulty3.png", "difficultyimage/Difficulty4.png", "difficultyimage/Difficulty5.png"};
char mazeimage[8][50] = {"mazeDesignImage/pixel.png", "mazeDesignImage/nebula.png", "mazeDesignImage/spectral.png", "mazeDesignImage/psi.png", "mazeDesignImage/crack.png", "mazeDesignImage/echo.png", "mazeDesignImage/phantom.png", "mazeDesignImage/spiral.png"};
char playgameintroimage[2][50] = {"playgameintro/intro.png", "playgameintro/intro2.png"};
char exitimage[100][100] = {"thanksimage/thanks (1).jpg", "thanksimage/thanks (2).jpg", "thanksimage/thanks (3).jpg", "thanksimage/thanks (4).jpg", "thanksimage/thanks (5).jpg", "thanksimage/thanks (6).jpg", "thanksimage/thanks (7).jpg", "thanksimage/thanks (8).jpg", "thanksimage/thanks (9).jpg", "thanksimage/thanks (10).jpg", "thanksimage/thanks (11).jpg", "thanksimage/thanks (12).jpg", "thanksimage/thanks (13).jpg", "thanksimage/thanks (14).jpg", "thanksimage/thanks (15).jpg", "thanksimage/thanks (16).jpg", "thanksimage/thanks (17).jpg", "thanksimage/thanks (18).jpg", "thanksimage/thanks (20).jpg", "thanksimage/thanks (20).jpg", "thanksimage/thanks (21).jpg", "thanksimage/thanks (22).jpg", "thanksimage/thanks (23).jpg", "thanksimage/thanks (24).jpg", "thanksimage/thanks (25).jpg", "thanksimage/thanks (26).jpg", "thanksimage/thanks (27).jpg", "thanksimage/thanks (28).jpg", "thanksimage/thanks (29).jpg", "thanksimage/thanks (30).jpg", "thanksimage/thanks (31).jpg", "thanksimage/thanks (32).jpg", "thanksimage/thanks (33).jpg", "thanksimage/thanks (34).jpg", "thanksimage/thanks (35).jpg", "thanksimage/thanks (36).jpg", "thanksimage/thanks (37).jpg", "thanksimage/thanks (38).jpg", "thanksimage/thanks (39).jpg", "thanksimage/thanks (40).jpg", "thanksimage/thanks (41).jpg", "thanksimage/thanks (42).jpg", "thanksimage/thanks (43).jpg", "thanksimage/thanks (44).jpg", "thanksimage/thanks (45).jpg", "thanksimage/thanks (46).jpg", "thanksimage/thanks (47).jpg", "thanksimage/thanks (48).jpg", "thanksimage/thanks (49).jpg", "thanksimage/thanks (50).jpg", "thanksimage/thanks (51).jpg", "thanksimage/thanks (52).jpg", "thanksimage/thanks (53).jpg", "thanksimage/thanks (54).jpg", "thanksimage/thanks (55).jpg", "thanksimage/thanks (56).jpg", "thanksimage/thanks (57).jpg", "thanksimage/thanks (58).jpg", "thanksimage/thanks (59).jpg", "thanksimage/thanks (60).jpg", "thanksimage/thanks (61).jpg", "thanksimage/thanks (62).jpg", "thanksimage/thanks (63).jpg", "thanksimage/thanks (64).jpg", "thanksimage/thanks (65).jpg", "thanksimage/thanks (66).jpg", "thanksimage/thanks (67).jpg", "thanksimage/thanks (68).jpg", "thanksimage/thanks (69).jpg", "thanksimage/thanks (70).jpg", "thanksimage/thanks (71).jpg", "thanksimage/thanks (72).jpg", "thanksimage/thanks (73).jpg", "thanksimage/thanks (74).jpg", "thanksimage/thanks (75).jpg", "thanksimage/thanks (76).jpg", "thanksimage/thanks (77).jpg", "thanksimage/thanks (78).jpg", "thanksimage/thanks (79).jpg", "thanksimage/thanks (80).jpg", "thanksimage/thanks (81).jpg", "thanksimage/thanks (82).jpg", "thanksimage/thanks (83).jpg", "thanksimage/thanks (84).jpg", "thanksimage/thanks (85).jpg", "thanksimage/thanks (86).jpg", "thanksimage/thanks (87).jpg", "thanksimage/thanks (88).jpg", "thanksimage/thanks (89).jpg", "thanksimage/thanks (90).jpg", "thanksimage/thanks (91).jpg", "thanksimage/thanks (92).jpg", "thanksimage/thanks (93).jpg", "thanksimage/thanks (94).jpg", "thanksimage/thanks (95).jpg", "thanksimage/thanks (96).jpg", "thanksimage/thanks (97).jpg", "thanksimage/thanks (98).jpg", "thanksimage/thanks (99).jpg", "thanksimage/thanks (100).jpg"};
char pauseimage[4][40] = {"pauseimage/pause (1).png", "pauseimage/pause (2).png", "pauseimage/pause (3).png", "pauseimage/pause (4).png"};
char backgroundimage[5][50] = {"bg/bg.png", "bg/bg (3).png", "bg/bg (1).png", "bg/bg (2).png", "bg/bg (4).png"};
char backgroundselectorimage[500][50] = {"slbg/slbg (1).jpg", "slbg/slbg (2).jpg", "slbg/slbg (3).jpg", "slbg/slbg (4).jpg", "slbg/slbg (5).jpg", "slbg/slbg (6).jpg", "slbg/slbg (7).jpg", "slbg/slbg (8).jpg", "slbg/slbg (9).jpg", "slbg/slbg (10).jpg", "slbg/slbg (11).jpg", "slbg/slbg (12).jpg", "slbg/slbg (13).jpg", "slbg/slbg (14).jpg", "slbg/slbg (15).jpg", "slbg/slbg (16).jpg", "slbg/slbg (17).jpg", "slbg/slbg (18).jpg", "slbg/slbg (19).jpg", "slbg/slbg (20).jpg", "slbg/slbg (21).jpg", "slbg/slbg (22).jpg", "slbg/slbg (23).jpg", "slbg/slbg (24).jpg", "slbg/slbg (25).jpg", "slbg/slbg (26).jpg", "slbg/slbg (27).jpg", "slbg/slbg (28).jpg", "slbg/slbg (29).jpg", "slbg/slbg (30).jpg", "slbg/slbg (31).jpg", "slbg/slbg (32).jpg", "slbg/slbg (33).jpg", "slbg/slbg (34).jpg", "slbg/slbg (35).jpg", "slbg/slbg (36).jpg", "slbg/slbg (37).jpg", "slbg/slbg (38).jpg", "slbg/slbg (39).jpg", "slbg/slbg (40).jpg", "slbg/slbg (41).jpg", "slbg/slbg (42).jpg", "slbg/slbg (43).jpg", "slbg/slbg (44).jpg", "slbg/slbg (45).jpg", "slbg/slbg (46).jpg", "slbg/slbg (47).jpg", "slbg/slbg (48).jpg", "slbg/slbg (49).jpg", "slbg/slbg (50).jpg", "slbg/slbg (51).jpg", "slbg/slbg (52).jpg", "slbg/slbg (53).jpg", "slbg/slbg (54).jpg", "slbg/slbg (55).jpg", "slbg/slbg (56).jpg", "slbg/slbg (57).jpg", "slbg/slbg (58).jpg", "slbg/slbg (59).jpg", "slbg/slbg (60).jpg", "slbg/slbg (61).jpg", "slbg/slbg (62).jpg", "slbg/slbg (63).jpg", "slbg/slbg (64).jpg", "slbg/slbg (65).jpg", "slbg/slbg (66).jpg", "slbg/slbg (67).jpg", "slbg/slbg (68).jpg", "slbg/slbg (69).jpg", "slbg/slbg (70).jpg", "slbg/slbg (71).jpg", "slbg/slbg (72).jpg", "slbg/slbg (73).jpg", "slbg/slbg (74).jpg", "slbg/slbg (75).jpg", "slbg/slbg (76).jpg", "slbg/slbg (77).jpg", "slbg/slbg (78).jpg", "slbg/slbg (79).jpg", "slbg/slbg (80).jpg", "slbg/slbg (81).jpg", "slbg/slbg (82).jpg", "slbg/slbg (83).jpg", "slbg/slbg (84).jpg", "slbg/slbg (85).jpg", "slbg/slbg (86).jpg", "slbg/slbg (87).jpg", "slbg/slbg (88).jpg", "slbg/slbg (89).jpg", "slbg/slbg (90).jpg", "slbg/slbg (91).jpg", "slbg/slbg (92).jpg", "slbg/slbg (93).jpg", "slbg/slbg (94).jpg", "slbg/slbg (95).jpg", "slbg/slbg (96).jpg", "slbg/slbg (97).jpg", "slbg/slbg (98).jpg", "slbg/slbg (99).jpg", "slbg/slbg (100).jpg", "slbg/slbg (101).jpg", "slbg/slbg (102).jpg", "slbg/slbg (103).jpg", "slbg/slbg (104).jpg", "slbg/slbg (105).jpg", "slbg/slbg (106).jpg", "slbg/slbg (107).jpg", "slbg/slbg (108).jpg", "slbg/slbg (109).jpg", "slbg/slbg (110).jpg", "slbg/slbg (111).jpg", "slbg/slbg (112).jpg", "slbg/slbg (113).jpg", "slbg/slbg (114).jpg", "slbg/slbg (115).jpg", "slbg/slbg (116).jpg", "slbg/slbg (117).jpg", "slbg/slbg (118).jpg", "slbg/slbg (119).jpg", "slbg/slbg (120).jpg", "slbg/slbg (121).jpg", "slbg/slbg (122).jpg", "slbg/slbg (123).jpg", "slbg/slbg (124).jpg", "slbg/slbg (125).jpg", "slbg/slbg (126).jpg", "slbg/slbg (127).jpg", "slbg/slbg (128).jpg", "slbg/slbg (129).jpg", "slbg/slbg (130).jpg", "slbg/slbg (131).jpg", "slbg/slbg (132).jpg", "slbg/slbg (133).jpg", "slbg/slbg (134).jpg", "slbg/slbg (135).jpg", "slbg/slbg (136).jpg", "slbg/slbg (137).jpg", "slbg/slbg (138).jpg", "slbg/slbg (139).jpg", "slbg/slbg (140).jpg", "slbg/slbg (141).jpg", "slbg/slbg (142).jpg", "slbg/slbg (143).jpg", "slbg/slbg (144).jpg", "slbg/slbg (145).jpg", "slbg/slbg (146).jpg", "slbg/slbg (147).jpg", "slbg/slbg (148).jpg", "slbg/slbg (149).jpg", "slbg/slbg (150).jpg", "slbg/slbg (151).jpg", "slbg/slbg (152).jpg", "slbg/slbg (153).jpg", "slbg/slbg (154).jpg", "slbg/slbg (155).jpg", "slbg/slbg (156).jpg", "slbg/slbg (157).jpg", "slbg/slbg (158).jpg", "slbg/slbg (159).jpg", "slbg/slbg (160).jpg", "slbg/slbg (161).jpg", "slbg/slbg (162).jpg", "slbg/slbg (163).jpg", "slbg/slbg (164).jpg", "slbg/slbg (165).jpg", "slbg/slbg (166).jpg", "slbg/slbg (167).jpg", "slbg/slbg (168).jpg", "slbg/slbg (169).jpg", "slbg/slbg (170).jpg", "slbg/slbg (171).jpg", "slbg/slbg (172).jpg", "slbg/slbg (173).jpg", "slbg/slbg (174).jpg", "slbg/slbg (175).jpg", "slbg/slbg (176).jpg", "slbg/slbg (177).jpg", "slbg/slbg (178).jpg", "slbg/slbg (179).jpg", "slbg/slbg (180).jpg", "slbg/slbg (181).jpg", "slbg/slbg (182).jpg", "slbg/slbg (183).jpg", "slbg/slbg (184).jpg", "slbg/slbg (185).jpg", "slbg/slbg (186).jpg", "slbg/slbg (187).jpg", "slbg/slbg (188).jpg", "slbg/slbg (189).jpg", "slbg/slbg (190).jpg", "slbg/slbg (191).jpg", "slbg/slbg (192).jpg", "slbg/slbg (193).jpg", "slbg/slbg (194).jpg", "slbg/slbg (195).jpg", "slbg/slbg (196).jpg", "slbg/slbg (197).jpg", "slbg/slbg (198).jpg", "slbg/slbg (199).jpg", "slbg/slbg (200).jpg", "slbg/slbg (201).jpg", "slbg/slbg (202).jpg", "slbg/slbg (203).jpg", "slbg/slbg (204).jpg", "slbg/slbg (205).jpg", "slbg/slbg (206).jpg", "slbg/slbg (207).jpg", "slbg/slbg (208).jpg", "slbg/slbg (209).jpg", "slbg/slbg (210).jpg", "slbg/slbg (211).jpg", "slbg/slbg (212).jpg", "slbg/slbg (213).jpg", "slbg/slbg (214).jpg", "slbg/slbg (215).jpg", "slbg/slbg (216).jpg", "slbg/slbg (217).jpg", "slbg/slbg (218).jpg", "slbg/slbg (219).jpg", "slbg/slbg (220).jpg", "slbg/slbg (221).jpg", "slbg/slbg (222).jpg", "slbg/slbg (223).jpg", "slbg/slbg (224).jpg", "slbg/slbg (225).jpg", "slbg/slbg (226).jpg", "slbg/slbg (227).jpg", "slbg/slbg (228).jpg", "slbg/slbg (229).jpg", "slbg/slbg (230).jpg", "slbg/slbg (231).jpg", "slbg/slbg (232).jpg", "slbg/slbg (233).jpg", "slbg/slbg (234).jpg", "slbg/slbg (235).jpg", "slbg/slbg (236).jpg", "slbg/slbg (237).jpg", "slbg/slbg (238).jpg", "slbg/slbg (239).jpg", "slbg/slbg (240).jpg", "slbg/slbg (241).jpg", "slbg/slbg (242).jpg", "slbg/slbg (243).jpg", "slbg/slbg (244).jpg", "slbg/slbg (245).jpg", "slbg/slbg (246).jpg", "slbg/slbg (247).jpg", "slbg/slbg (248).jpg", "slbg/slbg (249).jpg", "slbg/slbg (250).jpg", "slbg/slbg (251).jpg", "slbg/slbg (252).jpg", "slbg/slbg (253).jpg", "slbg/slbg (254).jpg", "slbg/slbg (255).jpg", "slbg/slbg (256).jpg", "slbg/slbg (257).jpg", "slbg/slbg (258).jpg", "slbg/slbg (259).jpg", "slbg/slbg (260).jpg", "slbg/slbg (261).jpg", "slbg/slbg (262).jpg", "slbg/slbg (263).jpg", "slbg/slbg (264).jpg", "slbg/slbg (265).jpg", "slbg/slbg (266).jpg", "slbg/slbg (267).jpg", "slbg/slbg (268).jpg", "slbg/slbg (269).jpg", "slbg/slbg (270).jpg", "slbg/slbg (271).jpg", "slbg/slbg (272).jpg", "slbg/slbg (273).jpg", "slbg/slbg (274).jpg", "slbg/slbg (275).jpg", "slbg/slbg (276).jpg", "slbg/slbg (277).jpg", "slbg/slbg (278).jpg", "slbg/slbg (279).jpg", "slbg/slbg (280).jpg", "slbg/slbg (281).jpg", "slbg/slbg (282).jpg", "slbg/slbg (283).jpg", "slbg/slbg (284).jpg", "slbg/slbg (285).jpg", "slbg/slbg (286).jpg", "slbg/slbg (287).jpg", "slbg/slbg (288).jpg", "slbg/slbg (289).jpg", "slbg/slbg (290).jpg", "slbg/slbg (291).jpg", "slbg/slbg (292).jpg", "slbg/slbg (293).jpg", "slbg/slbg (294).jpg", "slbg/slbg (295).jpg", "slbg/slbg (296).jpg", "slbg/slbg (297).jpg", "slbg/slbg (298).jpg", "slbg/slbg (299).jpg", "slbg/slbg (300).jpg", "slbg/slbg (301).jpg", "slbg/slbg (302).jpg", "slbg/slbg (303).jpg", "slbg/slbg (304).jpg", "slbg/slbg (305).jpg", "slbg/slbg (306).jpg", "slbg/slbg (307).jpg", "slbg/slbg (308).jpg", "slbg/slbg (309).jpg", "slbg/slbg (310).jpg", "slbg/slbg (311).jpg", "slbg/slbg (312).jpg", "slbg/slbg (313).jpg", "slbg/slbg (314).jpg", "slbg/slbg (315).jpg", "slbg/slbg (316).jpg", "slbg/slbg (317).jpg", "slbg/slbg (318).jpg", "slbg/slbg (319).jpg", "slbg/slbg (320).jpg", "slbg/slbg (321).jpg", "slbg/slbg (322).jpg", "slbg/slbg (323).jpg", "slbg/slbg (324).jpg", "slbg/slbg (325).jpg", "slbg/slbg (326).jpg", "slbg/slbg (327).jpg", "slbg/slbg (328).jpg", "slbg/slbg (329).jpg", "slbg/slbg (330).jpg", "slbg/slbg (331).jpg", "slbg/slbg (332).jpg", "slbg/slbg (333).jpg", "slbg/slbg (334).jpg", "slbg/slbg (335).jpg", "slbg/slbg (336).jpg", "slbg/slbg (337).jpg", "slbg/slbg (338).jpg", "slbg/slbg (339).jpg", "slbg/slbg (340).jpg", "slbg/slbg (341).jpg", "slbg/slbg (342).jpg", "slbg/slbg (343).jpg", "slbg/slbg (344).jpg", "slbg/slbg (345).jpg", "slbg/slbg (346).jpg", "slbg/slbg (347).jpg", "slbg/slbg (348).jpg", "slbg/slbg (349).jpg", "slbg/slbg (350).jpg", "slbg/slbg (351).jpg", "slbg/slbg (352).jpg", "slbg/slbg (353).jpg", "slbg/slbg (354).jpg", "slbg/slbg (355).jpg", "slbg/slbg (356).jpg", "slbg/slbg (357).jpg", "slbg/slbg (358).jpg", "slbg/slbg (359).jpg", "slbg/slbg (360).jpg", "slbg/slbg (361).jpg", "slbg/slbg (362).jpg", "slbg/slbg (363).jpg", "slbg/slbg (364).jpg", "slbg/slbg (365).jpg", "slbg/slbg (366).jpg", "slbg/slbg (367).jpg", "slbg/slbg (368).jpg", "slbg/slbg (369).jpg", "slbg/slbg (370).jpg", "slbg/slbg (371).jpg", "slbg/slbg (372).jpg", "slbg/slbg (373).jpg", "slbg/slbg (374).jpg", "slbg/slbg (375).jpg", "slbg/slbg (376).jpg", "slbg/slbg (377).jpg", "slbg/slbg (378).jpg", "slbg/slbg (379).jpg", "slbg/slbg (380).jpg", "slbg/slbg (381).jpg", "slbg/slbg (382).jpg", "slbg/slbg (383).jpg", "slbg/slbg (384).jpg", "slbg/slbg (385).jpg", "slbg/slbg (386).jpg", "slbg/slbg (387).jpg", "slbg/slbg (388).jpg", "slbg/slbg (389).jpg", "slbg/slbg (390).jpg", "slbg/slbg (391).jpg", "slbg/slbg (392).jpg", "slbg/slbg (393).jpg", "slbg/slbg (394).jpg", "slbg/slbg (395).jpg", "slbg/slbg (396).jpg", "slbg/slbg (397).jpg", "slbg/slbg (398).jpg", "slbg/slbg (399).jpg", "slbg/slbg (400).jpg", "slbg/slbg (401).jpg", "slbg/slbg (402).jpg", "slbg/slbg (403).jpg", "slbg/slbg (404).jpg", "slbg/slbg (405).jpg", "slbg/slbg (406).jpg", "slbg/slbg (407).jpg", "slbg/slbg (408).jpg", "slbg/slbg (409).jpg", "slbg/slbg (410).jpg", "slbg/slbg (411).jpg", "slbg/slbg (412).jpg", "slbg/slbg (413).jpg", "slbg/slbg (414).jpg", "slbg/slbg (415).jpg", "slbg/slbg (416).jpg", "slbg/slbg (417).jpg", "slbg/slbg (418).jpg", "slbg/slbg (419).jpg", "slbg/slbg (420).jpg", "slbg/slbg (421).jpg", "slbg/slbg (422).jpg", "slbg/slbg (423).jpg", "slbg/slbg (424).jpg", "slbg/slbg (425).jpg", "slbg/slbg (426).jpg", "slbg/slbg (427).jpg", "slbg/slbg (428).jpg", "slbg/slbg (429).jpg", "slbg/slbg (430).jpg", "slbg/slbg (431).jpg", "slbg/slbg (432).jpg", "slbg/slbg (433).jpg", "slbg/slbg (434).jpg", "slbg/slbg (435).jpg", "slbg/slbg (436).jpg", "slbg/slbg (437).jpg", "slbg/slbg (438).jpg", "slbg/slbg (439).jpg", "slbg/slbg (440).jpg", "slbg/slbg (441).jpg", "slbg/slbg (442).jpg", "slbg/slbg (443).jpg", "slbg/slbg (444).jpg", "slbg/slbg (445).jpg", "slbg/slbg (446).jpg", "slbg/slbg (447).jpg", "slbg/slbg (448).jpg", "slbg/slbg (449).jpg", "slbg/slbg (450).jpg", "slbg/slbg (451).jpg", "slbg/slbg (452).jpg", "slbg/slbg (453).jpg", "slbg/slbg (454).jpg", "slbg/slbg (455).jpg", "slbg/slbg (456).jpg", "slbg/slbg (457).jpg", "slbg/slbg (458).jpg", "slbg/slbg (459).jpg", "slbg/slbg (460).jpg", "slbg/slbg (461).jpg", "slbg/slbg (462).jpg", "slbg/slbg (463).jpg", "slbg/slbg (464).jpg", "slbg/slbg (465).jpg", "slbg/slbg (466).jpg", "slbg/slbg (467).jpg", "slbg/slbg (468).jpg", "slbg/slbg (469).jpg", "slbg/slbg (470).jpg", "slbg/slbg (471).jpg", "slbg/slbg (472).jpg", "slbg/slbg (473).jpg", "slbg/slbg (474).jpg", "slbg/slbg (475).jpg", "slbg/slbg (476).jpg", "slbg/slbg (477).jpg", "slbg/slbg (478).jpg", "slbg/slbg (479).jpg", "slbg/slbg (480).jpg", "slbg/slbg (481).jpg", "slbg/slbg (482).jpg", "slbg/slbg (483).jpg", "slbg/slbg (484).jpg", "slbg/slbg (485).jpg", "slbg/slbg (486).jpg", "slbg/slbg (487).jpg", "slbg/slbg (488).jpg", "slbg/slbg (489).jpg", "slbg/slbg (490).jpg", "slbg/slbg (491).jpg", "slbg/slbg (492).jpg", "slbg/slbg (493).jpg", "slbg/slbg (494).jpg", "slbg/slbg (495).jpg", "slbg/slbg (496).jpg", "slbg/slbg (497).jpg", "slbg/slbg (498).jpg", "slbg/slbg (499).jpg", "slbg/slbg (500).jpg"};
char scoreshowimage[100][50] = {"congrats/congrats (1).jpg", "congrats/congrats (2).jpg", "congrats/congrats (3).jpg", "congrats/congrats (4).jpg", "congrats/congrats (5).jpg", "congrats/congrats (6).jpg", "congrats/congrats (7).jpg", "congrats/congrats (8).jpg", "congrats/congrats (9).jpg", "congrats/congrats (10).jpg", "congrats/congrats (11).jpg", "congrats/congrats (12).jpg", "congrats/congrats (13).jpg", "congrats/congrats (14).jpg", "congrats/congrats (15).jpg", "congrats/congrats (16).jpg", "congrats/congrats (17).jpg", "congrats/congrats (18).jpg", "congrats/congrats (20).jpg", "congrats/congrats (20).jpg", "congrats/congrats (21).jpg", "congrats/congrats (22).jpg", "congrats/congrats (23).jpg", "congrats/congrats (24).jpg", "congrats/congrats (25).jpg", "congrats/congrats (26).jpg", "congrats/congrats (27).jpg", "congrats/congrats (28).jpg", "congrats/congrats (29).jpg", "congrats/congrats (30).jpg", "congrats/congrats (31).jpg", "congrats/congrats (32).jpg", "congrats/congrats (33).jpg", "congrats/congrats (34).jpg", "congrats/congrats (35).jpg", "congrats/congrats (36).jpg", "congrats/congrats (37).jpg", "congrats/congrats (38).jpg", "congrats/congrats (39).jpg", "congrats/congrats (40).jpg", "congrats/congrats (41).jpg", "congrats/congrats (42).jpg", "congrats/congrats (43).jpg", "congrats/congrats (44).jpg", "congrats/congrats (45).jpg", "congrats/congrats (46).jpg", "congrats/congrats (47).jpg", "congrats/congrats (48).jpg", "congrats/congrats (49).jpg", "congrats/congrats (50).jpg", "congrats/congrats (51).jpg", "congrats/congrats (52).jpg", "congrats/congrats (53).jpg", "congrats/congrats (54).jpg", "congrats/congrats (55).jpg", "congrats/congrats (56).jpg", "congrats/congrats (57).jpg", "congrats/congrats (58).jpg", "congrats/congrats (59).jpg", "congrats/congrats (60).jpg", "congrats/congrats (61).jpg", "congrats/congrats (62).jpg", "congrats/congrats (63).jpg", "congrats/congrats (64).jpg", "congrats/congrats (65).jpg", "congrats/congrats (66).jpg", "congrats/congrats (67).jpg", "congrats/congrats (68).jpg", "congrats/congrats (69).jpg", "congrats/congrats (70).jpg", "congrats/congrats (71).jpg", "congrats/congrats (72).jpg", "congrats/congrats (73).jpg", "congrats/congrats (74).jpg", "congrats/congrats (75).jpg", "congrats/congrats (76).jpg", "congrats/congrats (77).jpg", "congrats/congrats (78).jpg", "congrats/congrats (79).jpg", "congrats/congrats (80).jpg", "congrats/congrats (81).jpg", "congrats/congrats (82).jpg", "congrats/congrats (83).jpg", "congrats/congrats (84).jpg", "congrats/congrats (85).jpg", "congrats/congrats (86).jpg", "congrats/congrats (87).jpg", "congrats/congrats (88).jpg", "congrats/congrats (89).jpg", "congrats/congrats (90).jpg", "congrats/congrats (91).jpg", "congrats/congrats (92).jpg", "congrats/congrats (93).jpg", "congrats/congrats (94).jpg", "congrats/congrats (95).jpg", "congrats/congrats (96).jpg", "congrats/congrats (97).jpg", "congrats/congrats (98).jpg", "congrats/congrats (99).jpg", "congrats/congrats (100).jpg"};
char life[5][50] = {"life/love (3).png", "life/love (2).png", "life/love (1).png", "life/love10.png", "life/love12.png"};

char pacmanRight[2][30] = {"pacman/pacman (1).png", "pacman/pacman (2).png"};
char pacmanLeft[2][30] = {"pacman/pacman (5).png", "pacman/pacman (6).png"};
char pacmanUp[2][30] = {"pacman/pacman (7).png", "pacman/pacman (8).png"};
char pacmanDown[2][30] = {"pacman/pacman (3).png", "pacman/pacman (4).png"};
char pacdeadscene[11][30] = {"pacdead/pacdead0.png", "pacdead/pacdead1.png", "pacdead/pacdead2.png", "pacdead/pacdead3.png", "pacdead/pacdead4.png", "pacdead/pacdead5.png", "pacdead/pacdead6.png", "pacdead/pacdead7.png", "pacdead/pacdead8.png", "pacdead/pacdead9.png", "pacdead/pacdead10.png"};
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
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
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
int maze4[21][40] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
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
        bool isPowerPellet = false;

        if (selected == 1 && (i == 0 || i == 18 || i == 149 || i == 104))
            isPowerPellet = true;
        else if (selected == 2 && (i == 0 || i == 18 || i == 165 || i == 156))
            isPowerPellet = true;
        else if (selected == 3 && (i == 84 || i == 292 || i == 100 || i == 200))
            isPowerPellet = true;
        else if (selected == 4 && (i == 15 || i == 50 || i == 87 || i == 135 || i == 172 || i == 244 || i == 327))
            isPowerPellet = true;

        if (isPowerPellet)
        {
            iSetColor(50, 205, 50); //  Sky blue
            iFilledCircle(x + 12, y + 12, 4.5);
            iSetColor(255, 140, 0); // Reset to yellow or any dot color
        }
        else
        {
            // Regular dot
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
        totalfood = 236;
    }
    else if (selected == 3)
    {
        totalfood = 362;
    }
    else if (selected == 4)
    {
        totalfood = 454;
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
    else if (difficulty)
    {
        iShowImage(0, 0, difficultyimage[difficultyc]);
    }
    else if (highscore)
    {
        iShowImage(0, 0, highscoreimage[highscorec]);

        for (int i = 0; i < line; i++)
        {
            if (i == 5)
                break;
            iSetColor(0, 0, 0);
            iText(215, 384 - (i * 84), name[i], GLUT_BITMAP_TIMES_ROMAN_24);
            iText(867, 390 - (i * 84), converter(point[i], temp), GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }

    else if (playgameintro)
    {
        iShowImage(0, 0, playgameintroimage[0]);
        iSetColor(255, 255, 255);
        iText(430, 282, namestr, GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if (settings)
    {
        iShowImage(0, 0, settingsimage[settingsc]);
    }
    else if (mazeselector)
    {
        iShowImage(0, 0, mazeselectorimage[mazeselectorc]);
    }
    else if (credits)
    {
        iShowImage(0, 0, creditimage[creditsc]);
    }
    else if (rules)
    {
        iShowImage(0, 0, rulesimage[rulesc]);
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

        iText(1056, 625, pacScore, GLUT_BITMAP_TIMES_ROMAN_24);
        for (int i = 0; i < pacmanlife; i++)
            iShowImage(1041 + 40 * i, 557, life[i]);
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
            playingstart = false;
            congrats = true;
        }

        if (!blueGhost)
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

        else
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
    }
    else if (congrats)
    {
        iShowImage(0, 0, scoreshowimage[congratsc]);
        iText(570, 300, pacScore, GLUT_BITMAP_TIMES_ROMAN_24);
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
        iShowImage(0, 0, backgroundselectorimage[backgroundselectorc]);
    }
};
void directionGenarator2(int ara[], int dir, int pookietype)
{
    if (ara[dir] == 0)
    {
        pookie[pookietype].flagLeft = true;
    }
    else if (ara[dir] == 1)
    {
        pookie[pookietype].flagRight = true;
    }
    else if (ara[dir] == 2)
    {
        pookie[pookietype].flagUp = true;
    }
    else if (ara[dir] == 3)
    {
        pookie[pookietype].flagDown = true;
    }
}
void directionGenarator(int a, int pookietype)
{
    time_t t;
    srand((unsigned)time(&t));
    int dir;
    pookie[pookietype].flagDown = false;
    pookie[pookietype].flagLeft = false;
    pookie[pookietype].flagRight = false;
    pookie[pookietype].flagUp = false;

    int para[4] = {-1, -1, -1, -1};
    bool flag = false;

    int distUp = calcDist(pookie[pookietype].x, pookie[pookietype].y + mazeCellWidth, pac.x, pac.y);
    int distDown = calcDist(pookie[pookietype].x, pookie[pookietype].y - mazeCellWidth, pac.x, pac.y);
    int distLeft = calcDist(pookie[pookietype].x - mazeCellWidth, pookie[pookietype].y, pac.x, pac.y);
    int distRight = calcDist(pookie[pookietype].x + mazeCellWidth, pookie[pookietype].y, pac.x, pac.y);
    int currentDist = calcDist(pookie[pookietype].x, pookie[pookietype].y, pac.x, pac.y);
    if (selected == 1)
    {
        if (a > 3)
        {
            if (!maze1[pookie[pookietype].cellY - 1][pookie[pookietype].cellX] && !flag)
            {
                if (distUp < currentDist)
                {
                    pookie[pookietype].flagUp = true;
                    flag = true;
                }
            }

            if (!maze1[pookie[pookietype].cellY + 1][pookie[pookietype].cellX] && !flag)
            {
                if (distDown < currentDist)
                {
                    pookie[pookietype].flagDown = true;
                    flag = true;
                }
            }

            if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX - 1] && !flag)
            {
                if (distLeft < currentDist)
                {
                    pookie[pookietype].flagLeft = true;
                    flag = true;
                }
            }

            if (!maze1[pookie[pookietype].cellY][pookie[pookietype].cellX + 1] && !flag)
            {
                if (distRight < currentDist)
                {
                    pookie[pookietype].flagRight = true;
                    flag = true;
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
                pookie[pookietype].flagLeft = true;
            else if (a == 1)
                pookie[pookietype].flagRight = true;
            else if (a == 2)
                pookie[pookietype].flagUp = true;
            else if (a == 3)
                pookie[pookietype].flagDown = true;
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
                    pookie[pookietype].flagUp = true;
                    flag = true;
                }
            }

            if (!maze2[pookie[pookietype].cellY + 1][pookie[pookietype].cellX] && !flag)
            {
                if (distDown < currentDist)
                {
                    pookie[pookietype].flagDown = true;
                    flag = true;
                }
            }

            if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX - 1] && !flag)
            {
                if (distLeft < currentDist)
                {
                    pookie[pookietype].flagLeft = true;
                    flag = true;
                }
            }

            if (!maze2[pookie[pookietype].cellY][pookie[pookietype].cellX + 1] && !flag)
            {
                if (distRight < currentDist)
                {
                    pookie[pookietype].flagRight = true;
                    flag = true;
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
                pookie[pookietype].flagLeft = true;
            else if (a == 1)
                pookie[pookietype].flagRight = true;
            else if (a == 2)
                pookie[pookietype].flagUp = true;
            else if (a == 3)
                pookie[pookietype].flagDown = true;
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
                    pookie[pookietype].flagUp = true;
                    flag = true;
                }
            }

            if (!maze3[pookie[pookietype].cellY + 1][pookie[pookietype].cellX] && !flag)
            {
                if (distDown < currentDist)
                {
                    pookie[pookietype].flagDown = true;
                    flag = true;
                }
            }

            if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX - 1] && !flag)
            {
                if (distLeft < currentDist)
                {
                    pookie[pookietype].flagLeft = true;
                    flag = true;
                }
            }

            if (!maze3[pookie[pookietype].cellY][pookie[pookietype].cellX + 1] && !flag)
            {
                if (distRight < currentDist)
                {
                    pookie[pookietype].flagRight = true;
                    flag = true;
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
                pookie[pookietype].flagLeft = true;
            else if (a == 1)
                pookie[pookietype].flagRight = true;
            else if (a == 2)
                pookie[pookietype].flagUp = true;
            else if (a == 3)
                pookie[pookietype].flagDown = true;
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
                    pookie[pookietype].flagUp = true;
                    flag = true;
                }
            }

            if (!maze4[pookie[pookietype].cellY + 1][pookie[pookietype].cellX] && !flag)
            {
                if (distDown < currentDist)
                {
                    pookie[pookietype].flagDown = true;
                    flag = true;
                }
            }

            if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX - 1] && !flag)
            {
                if (distLeft < currentDist)
                {
                    pookie[pookietype].flagLeft = true;
                    flag = true;
                }
            }

            if (!maze4[pookie[pookietype].cellY][pookie[pookietype].cellX + 1] && !flag)
            {
                if (distRight < currentDist)
                {
                    pookie[pookietype].flagRight = true;
                    flag = true;
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
                pookie[pookietype].flagLeft = true;
            else if (a == 1)
                pookie[pookietype].flagRight = true;
            else if (a == 2)
                pookie[pookietype].flagUp = true;
            else if (a == 3)
                pookie[pookietype].flagDown = true;
        }
    }
}

int calcDist(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
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
            mazeWidth = 456; // 36*mazeCellWidth
            mazeHeight = 408;
        }
        else if (selected == 4)
        {
            mazeX = 72;
            mazeY = 48;
            mazeWidth = 504;
            mazeHeight = 456;
        }

        for (int pookietype = 0; pookietype < 4; pookietype++)
        {
            int px = pac.x;
            int py = pac.y;
            if (scatter)
            {
                if (pookietype == 0)
                {
                    px = mazeX + px;
                    py = mazeY + py;
                }
                else if (pookietype == 1)
                {
                    px = mazeX;
                    py = mazeY + py;
                }
                else if (pookietype == 2)
                {
                    px = mazeX;
                    py = mazeY + py / 2;
                }
                else if (pookietype == 3)
                {
                    px = mazeX + px / 3;
                    py = mazeY + py / 3;
                }
            }
            if (blast)
            {
                if (pookietype == 0)
                {
                    px = pac.x;
                    py = pac.y;
                }
                else if (pookietype == 1)
                {
                    px = pac.x;
                    py = pac.y;
                }
                else if (pookietype == 2)
                {
                    px = pac.x;
                    py = pac.y;
                }
                else if (pookietype == 3)
                {
                    px = pac.x;
                    py = pac.y;
                }
            }
            if (chase)
            {
                if (pookietype == 3)
                {
                    // Pinky (predicts ahead)
                    if (pac.rightCount)
                        px += mazeCellWidth * 4;
                    else if (pac.leftCount)
                        px -= mazeCellWidth * 4;
                    else if (pac.upCount)
                        py += mazeCellWidth * 4;
                    else if (pac.downCount)
                        py -= mazeCellWidth * 4;
                }
                else if (pookietype == 0)
                {
                    // Inky (predicts behind)
                    if (pac.rightCount)
                        px -= mazeCellWidth * 4;
                    else if (pac.leftCount)
                        px += mazeCellWidth * 4;
                    else if (pac.upCount)
                        py -= mazeCellWidth * 4;
                    else if (pac.downCount)
                        py += mazeCellWidth * 4;
                }
                else if (pookietype == 2)
                {
                    // Clyde (ambush from above)
                    py += mazeCellWidth * 4;
                }
                // pookieType == 1 is Blinky – default chase to Pac-Man, no offset
            }
            int distUp = calcDist(pookie[pookietype].x, pookie[pookietype].y + mazeCellWidth, px, py);
            int distDown = calcDist(pookie[pookietype].x, pookie[pookietype].y - mazeCellWidth, px, py);
            int distLeft = calcDist(pookie[pookietype].x - mazeCellWidth, pookie[pookietype].y, px, py);
            int distRight = calcDist(pookie[pookietype].x + mazeCellWidth, pookie[pookietype].y, px, py);
            int currentDist = calcDist(pookie[pookietype].x, pookie[pookietype].y, px, py);

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
                        pookie[pookietype].flagRight = true;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = false;

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

                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = true;
                        pookie[pookietype].flagUp = false;

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

                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = true;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = false;

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

                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = true;

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

                        pookie[pookietype].flagRight = true;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = false;

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

                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = true;
                        pookie[pookietype].flagUp = false;

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

                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = true;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = false;

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

                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = true;

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
                        pookie[pookietype].flagRight = true;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = false;

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
                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = true;
                        pookie[pookietype].flagUp = false;

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
                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = true;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = false;

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
                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = true;

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
                        pookie[pookietype].flagRight = true;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = false;

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
                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = true;
                        pookie[pookietype].flagUp = false;

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
                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = true;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = false;

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
                        pookie[pookietype].flagRight = false;
                        pookie[pookietype].flagLeft = false;
                        pookie[pookietype].flagDown = false;
                        pookie[pookietype].flagUp = true;

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
        else if (soundOn == false)
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
        else if (mx >= 260 && my >= 179 && mx <= 697 && my <= 245)
        {
            pausec = 3;
        }
        else
            pausec = 0;
    }
    else if (rules)
    {
        if ((mx >= 973 && mx <= 1174) && (my >= 71 && my <= 127))
        {
            rulesc = 1;
        }
        else
            rulesc = 0;
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
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        printf("mx=%d my=%d", mx, my);
        if (mainmenu)
        {
            if (mx >= 382 && my >= 579 && mx <= 765 && my <= 661)
            {
                specialthanks = true;
                mainmenu = false;
            }
            else if (mx >= 425 && my >= 476 && mx <= 678 && my <= 508)
            {
                playgameintro = true;
                mainmenu = false;
            }
            else if (mx >= 417 && my >= 404 && mx <= 697 && my <= 437)
            {
                highscore = true;
                mainmenu = false;
            }
            else if (mx >= 424 && my >= 331 && mx <= 631 && my <= 357)
            {
                settings = true;
                mainmenu = false;
            }
            else if (mx >= 423 && my >= 253 && mx <= 670 && my <= 285)
            {
                difficulty = true;
                mainmenu = false;
            }
            else if (mx >= 424 && my >= 184 && mx <= 613 && my <= 211)
            {
                credits = true;
                mainmenu = false;
            }
            else if (mx >= 419 && my >= 32 && mx <= 529 && my <= 71)
            {
                quit = true;
                mainmenu = false;
            }
            else if (mx >= 415 && my >= 109 && mx <= 565 && my <= 136)
            {
                rules = true;
                mainmenu = false;
            }
        }
        else if (specialthanks)
        {
            if (mx >= 1027 && my >= 42 && mx <= 1148 && my <= 94)
            {
                mainmenu = true;
                specialthanks = false;
            }
        }
        else if (highscore)
        {
            if ((mx >= 1040 && mx <= 1150) && (my >= 42 && my <= 88))
            {
                highscore = false;
                mainmenu = true;
            }
        }
        else if (difficulty)
        {
            if ((mx >= 46 && mx <= 233) && (my >= 82 && my <= 140))
            {
                difficulty = false;
                mainmenu = true;
            }
            else if ((mx >= 468 && mx <= 697) && (my >= 397 && my <= 448))
            {
                diffSpeed = 2;
                difficultyc = 0;
            }
            else if ((mx >= 460 && mx <= 805) && (my >= 306 && my <= 364))
            {
                diffSpeed = 3;
                difficultyc = 1;
            }
            else if ((mx >= 454 && mx <= 720) && (my >= 229 && my <= 280))
            {
                diffSpeed = 4;
                difficultyc = 2;
            }
            else if ((mx >= 456 && mx <= 817) && (my >= 137 && my <= 200))
            {
                diffSpeed = 4;
                difficultyc = 3;
                pacspeed = 4;
                chase = true;
            }
            else
            {
                diffSpeed = 2;
                difficultyc = 0;
            }
        }
        if (playgameintro)
        {
            if ((mx >= 18 && mx <= 161) && (my >= 36 && my <= 87))
            {
                playgameintro = false;
                mainmenu = true;
            }
            else if (mx >= 301 && my >= 245 && mx <= 866 && my <= 339)
            {
                typingName = true;
            }
        }
        else if (settings)
        {
            if (soundOn)
            {
                if ((mx >= 408 && mx <= 783) && (my >= 388 && my <= 439))
                {
                    soundOn = false;
                }
                else if ((mx >= 380 && mx <= 828) && (my >= 277 && my <= 320))
                {
                    mazeselector = true;
                    settings = false;
                }
                else if ((mx >= 964 && mx <= 1172) && (my >= 59 && my <= 115))
                {
                    settings = false;
                    mainmenu = true;
                }
            }
            else
            {
                if ((mx >= 408 && mx <= 783) && (my >= 388 && my <= 439))
                {
                    soundOn = true;
                }
                else if ((mx >= 380 && mx <= 828) && (my >= 277 && my <= 320))
                {
                    mazeselector = true;
                    settings = false;
                }
                else if ((mx >= 964 && mx <= 1172) && (my >= 59 && my <= 115))
                {
                    settings = false;
                    mainmenu = true;
                }
            }
        }

        else if (mazeselector)
        {
            if (mx >= 146 && my >= 516 && mx <= 378 && my <= 627) // pixel
            {
                mazeselectorc = 0;
                maze = 0;
                mazeselector = false;
                settings = true;
            }
            else if (mx >= 79 && my >= 310 && mx <= 323 && my <= 428) // nebula
            {
                mazeselectorc = 1;
                maze = 1;
                mazeselector = false;
                settings = true;
            }
            else if (mx >= 126 && my >= 95 && mx <= 395 && my <= 217) // spectral
            {
                mazeselectorc = 2;
                mazeselector = false;
                maze = 2;
                settings = true;
            }
            else if (mx >= 530 && my >= 51 && mx <= 745 && my <= 174) // psi
            {
                mazeselectorc = 3;
                mazeselector = false;
                settings = true;
                maze = 3;
            }
            else if (mx >= 854 && my >= 66 && mx <= 1108 && my <= 189) // crack
            {
                mazeselectorc = 4;
                mazeselector = false;
                settings = true;
                maze = 4;
            }
            else if (mx >= 887 && my >= 254 && mx <= 1126 && my <= 383) // echo
            {
                mazeselectorc = 5;
                mazeselector = false;
                settings = true;
                maze = 5;
            }
            else if (mx >= 853 && my >= 460 && mx <= 1087 && my <= 591) // phantom
            {
                mazeselectorc = 6;
                mazeselector = false;
                settings = true;
                maze = 6;
            }
            else if (mx >= 493 && my >= 527 && mx <= 735 && my <= 664)
            {
                mazeselectorc = 7;
                mazeselector = false;
                settings = true;
                maze = 7;
            } // spiral
        }
        else if (rules)
        {
            if ((mx >= 973 && mx <= 1174) && (my >= 71 && my <= 127))
            {
                rules = false;
                mainmenu = true;
            }
        }
        else if (credits)
        {

            if ((mx >= 957 && mx <= 1182) && (my >= 36 && my <= 104))
            {
                credits = false;
                mainmenu = true;
            }
        }
        else if (levelselect)
        {
            if ((mx >= 455 && mx <= 659) && (my >= 425 && my <= 492))
            {
                selected = 1;
                levelselect = false;
                playingstart = true;
                levelintro = 0;
                pacinitialcord();
                pookieinitialcoordinate();
                foodCoordinateStore();
                foodcount();
            }
            else if ((mx <= 653 && mx >= 454) && (my <= 388 && my >= 331))
            {
                selected = 2;
                levelselect = false;
                playingstart = true;
                levelintro = 0;
                pacinitialcord();
                pookieinitialcoordinate();
                foodCoordinateStore();
                foodcount();
            }
            else if ((mx >= 453 && my >= 229 && mx <= 655 && my <= 280))
            {
                selected = 3;
                levelselect = false;
                playingstart = true;

                levelintro = 0;
                pacinitialcord();
                pookieinitialcoordinate();
                foodCoordinateStore();
                foodcount();
            }
            else if (mx <= 664 && my <= 180 && mx >= 444 && my >= 126)
            {
                selected = 4;
                levelselect = false;
                playingstart = true;

                levelintro = 0;
                pacinitialcord();
                pookieinitialcoordinate();
                foodCoordinateStore();
                foodcount();
            }
        }
        else if (quit)
        {
            if ((mx >= 289 && mx <= 415) && (my >= 245 && my <= 299))
            {
                exitintro = true;
                quit = false;
            }
            else if ((mx >= 741 && mx <= 858) && (my >= 252 && my <= 302))
            {
                quitc = 0;
                quit = false;
                mainmenu = true;
            }
        }
        else if (pause)
        {
            if (mx >= 257 && my >= 420 && mx <= 698 && my <= 494)
            {
                pause = false;
                mainmenu = true;
                iResumeAll();
            }
            else if (mx >= 261 && my >= 299 && mx <= 534 && my <= 372)
            {
                playingstart = true;
                pause = false;
                iResumeAll();
            }
            else if (mx >= 260 && my >= 179 && mx <= 697 && my <= 245)
            {
                backgroundselector = true;
                pause = false;
            }
        }
        else if (playingstart)
        {
            if (mx >= 26 && my >= 599 && mx <= 177 && my <= 644)
            {
                pause = true;
                playingstart = false;
                iPauseAll();
            }
        }
        else if (backgroundselector)
        {
            if (mx >= 121 && my >= 273 && mx <= 413 && my <= 501)
            {
                bgimage = 0;
                backgroundselector = false;
                pause = true;
                backgroundselectorc = 0;
            }
            else if (mx >= 448 && my >= 323 && mx <= 760 && my <= 504)
            {
                bgimage = 1;
                backgroundselector = false;
                pause = true;
                backgroundselectorc = 0;
            }
            else if (mx >= 795 && my >= 327 && mx <= 1092 && my <= 495)
            {
                bgimage = 2;
                backgroundselector = false;
                pause = true;
                backgroundselectorc = 0;
            }
            else if (mx >= 252 && my >= 63 && mx <= 558 && my <= 238)
            {
                bgimage = 3;
                backgroundselector = false;
                pause = true;
                backgroundselectorc = 0;
            }
            else if (mx >= 627 && my >= 79 && mx <= 934 && my <= 238)
            {
                bgimage = 4;
                backgroundselector = false;
                backgroundselectorc = 0;

                pause = true;
            }
        }
    }
};

void foodCoordinateStore()
{
    /*  How foodXcor and foodYcor are Used
        foodXcor[i][0]: stores the X-coordinate for the i-th food item.

        foodYcor[i]: stores the corresponding Y-coordinate for the i-th food item.

        foodXcor[i][1]: acts as a status flag, where:

        0 means uneaten food,

       -1 means eaten (i.e. don’t render),

       -2 (if used) marks special fruit or power pellets.*/

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
void iKeyboard(unsigned char key)
{
    if (startintro)
    {
        if (key == 13)
        {
            startintro = false;
            mainmenu = true;
        }
    }
    else if (congrats)
    {
        if (key == '\r')
        {
            congrats = false;
            mainmenu = true;
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
                blueGhost = false;
                for (int i = 0; i < 4; i++)
                {
                    pookie[i].blueOn = false;
                }

                playgameintro = false;
                levelselect = true;
                iResumeAll();
            }
            else if (key == 27) // ESC key
            {
                memset(namestr, 0, sizeof(namestr));
                len = 0;
                playgameintro = false;
                mainmenu = true;
            }
            else if (len && key == 8) // BACKSPACE
            {
                namestr[--len] = '\0';
            }
            else if (len < 99) // Add new character if space available
            {
                namestr[len++] = key;
                namestr[len] = '\0'; // Always null-terminate
            }
        }
    }
}
void bluetimecheck()
{
    if (blueGhost)
    {
        blueGhost--;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            pookie[i].blueOn = false;
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
                pac.downCount = false;
                pac.upCount = false;
                pac.leftCount = false;
                pac.rightCount = true;
                pac.smoothRight = false;
            }
            else if (pac.smoothLeft && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze1[cellY][cellX - 1])
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.upCount = false;
                pac.leftCount = true;
                pac.smoothLeft = false;
            }
            else if (pac.smoothUp && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze1[cellY - 1][cellX])
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = true;
                pac.smoothUp = false;
            }
            else if (pac.smoothDown && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze1[cellY + 1][cellX])
            {
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = false;
                pac.downCount = true;
                pac.smoothDown = false;
            }
        }
        if (selected == 2)
        {
            if (pac.smoothRight && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze2[cellY][cellX + 1])
            {
                pac.downCount = false;
                pac.upCount = false;
                pac.leftCount = false;
                pac.rightCount = true;
                pac.smoothRight = false;
            }
            else if (pac.smoothLeft && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze2[cellY][cellX - 1])
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.upCount = false;
                pac.leftCount = true;
                pac.smoothLeft = false;
            }
            else if (pac.smoothUp && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze2[cellY - 1][cellX])
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = true;
                pac.smoothUp = false;
            }
            else if (pac.smoothDown && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze2[cellY + 1][cellX])
            {
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = false;
                pac.downCount = true;
                pac.smoothDown = false;
            }
        }
        if (selected == 3)
        {
            if (pac.smoothRight && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze3[cellY][cellX + 1])
            {
                pac.downCount = false;
                pac.upCount = false;
                pac.leftCount = false;
                pac.rightCount = true;
                pac.smoothRight = false;
            }
            else if (pac.smoothLeft && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze3[cellY][cellX - 1])
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.upCount = false;
                pac.leftCount = true;
                pac.smoothLeft = false;
            }
            else if (pac.smoothUp && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze3[cellY - 1][cellX])
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = true;
                pac.smoothUp = false;
            }
            else if (pac.smoothDown && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze3[cellY + 1][cellX])
            {
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = false;
                pac.downCount = true;
                pac.smoothDown = false;
            }
        }
        if (selected == 4)
        {
            if (pac.smoothRight && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze4[cellY][cellX + 1])
            {
                pac.downCount = false;
                pac.upCount = false;
                pac.leftCount = false;
                pac.rightCount = true;
                pac.smoothRight = false;
            }
            else if (pac.smoothLeft && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze4[cellY][cellX - 1])
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.upCount = false;
                pac.leftCount = true;
                pac.smoothLeft = false;
            }
            else if (pac.smoothUp && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze4[cellY - 1][cellX])
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = true;
                pac.smoothUp = false;
            }
            else if (pac.smoothDown && !(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth) && !maze4[cellY + 1][cellX])
            {
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = false;
                pac.downCount = true;
                pac.smoothDown = false;
            }
        }
        foodhelp++;
        if (!(foodhelp % fruitTimeInterval) && foodXcor[*foodCor][1] != -2 && foodXcor[*foodCor][1] != 0)
        {
            foodCor = &fruitGen[rand() % (t - 1)];
            foodXcor[*foodCor][1] = -2;
            randGen = rand() % 16;
        }
        if (totalfood == 0)
        {
            congrats = true;
            DataAnalysis();
            playingstart = false;
        }

        for (int i = 0; i <= foodNum; i++)
        {
            if ((pac.x == foodXcor[i][0]) && (pac.y == foodYcor[i]) && foodXcor[i][1] != -1)
            {
                if (foodXcor[i][1] == -2)
                {
                    if (randGen == 15 || randGen == 12)
                    {
                        pacmanlife++;
                    }
                    foodXcor[i][1] = -1;
                    score += 1000;
                    converter(score, pacScore);
                }
                else
                {
                    totalfood--;
                    printf("totalfood=%d ", totalfood);
                    foodXcor[i][1] = -1;
                    score += 10;
                    converter(score, pacScore);
                    fruitGen[t++] = i;
                    if (score > 1000)
                    {
                        chase = true;
                        scatter = false;
                    }
                    if (score > 6000)
                    {
                        chase = false;
                        blast = true;
                    }
                }
                if ((i == 0 || i == 18 || i == 149 || i == 104) && selected == 1)
                {

                    blueScore = -1;
                    score += 40;
                    blueGhost = 10; // add foodXcor[i][1]!=-2
                    for (int i = 0; i < 4; i++)
                        pookie[i].blueOn = true;
                }
                else if ((i == 0 || i == 18 || i == 165 || i == 156) && selected == 2)
                {

                    blueScore = -1;
                    score += 40;
                    blueGhost = 10; // add foodXcor[i][1]!=-2
                    for (int i = 0; i < 4; i++)
                        pookie[i].blueOn = true;
                }
                else if (selected == 3 && (i == 84 || i == 292 || i == 100 || i == 200))
                {

                    blueScore = -1;
                    score += 40;
                    blueGhost = 10; // add foodXcor[i][1]!=-2
                    for (int i = 0; i < 4; i++)
                        pookie[i].blueOn = true;
                }
                else if (selected == 4 && (i == 15 || i == 50 || i == 87 || i == 135 || i == 172 || i == 244 || i == 327))
                {

                    blueScore = -1;
                    score += 40;
                    blueGhost = 10; // add foodXcor[i][1]!=-2
                    for (int i = 0; i < 4; i++)
                        pookie[i].blueOn = true;
                }
            }
        }
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
                    pacdead = true;
                    iPauseTimer(3);
                    iPauseTimer(2);
                }
                else
                {
                    if (pookie[i].blueOn)
                    {

                        blueScore++;
                        score += (100) * pow(3, blueScore);
                        converter(score, pacScore);
                        pookie[i].blueOn = false;
                        if (selected == 1)
                        {
                            if (i == 0)
                            {
                                pookie[0].cellX = 9; // Inky
                                pookie[0].cellY = 9;
                                pookie[0].x = 168 + (pookie[0].cellX) * mazeCellWidth;
                                pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
                                pookie[0].flagRight = true;
                                pookie[0].speed = diffSpeed;
                            }
                            else if (i == 1)
                            {
                                pookie[1].cellX = 10; // Blinky
                                pookie[1].cellY = 9;
                                pookie[1].x = 168 + (pookie[1].cellX) * mazeCellWidth;
                                pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
                                pookie[1].flagUp = true;
                                pookie[1].speed = diffSpeed;
                            }
                            else if (i == 2)
                            {

                                pookie[2].cellX = 10; // Pinky
                                pookie[2].cellY = 9;
                                pookie[2].x = 168 + (pookie[2].cellX) * mazeCellWidth;
                                pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
                                pookie[2].flagRight = true;
                                pookie[2].speed = diffSpeed;
                            }
                            else if (i == 3)
                            {
                                pookie[3].cellX = 11; // Clyde
                                pookie[3].cellY = 9;
                                pookie[3].x = 168 + (pookie[3].cellX) * mazeCellWidth;
                                pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
                                pookie[3].flagRight = true;
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
                                pookie[0].flagRight = true;
                                pookie[0].speed = diffSpeed;
                            }
                            else if (i == 1)
                            {
                                pookie[1].cellX = 10; // Blinky
                                pookie[1].cellY = 8;
                                pookie[1].x = 168 + (pookie[1].cellX) * mazeCellWidth;
                                pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
                                pookie[1].flagUp = true;
                                pookie[1].speed = diffSpeed;
                            }
                            else if (i == 2)
                            {
                                pookie[2].cellX = 10; // Pinky
                                pookie[2].cellY = 8;
                                pookie[2].x = 168 + (pookie[2].cellX) * mazeCellWidth;
                                pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
                                pookie[2].flagRight = true;
                                pookie[2].speed = diffSpeed;
                            }
                            else if (i == 3)
                            {
                                pookie[3].cellX = 11; // Clyde
                                pookie[3].cellY = 8;
                                pookie[3].x = 168 + (pookie[3].cellX) * mazeCellWidth;
                                pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
                                pookie[3].flagRight = true;
                                pookie[3].speed = diffSpeed;
                            }
                        }
                        else if (selected == 3)
                        {
                            if (i == 0)
                            {
                                pookie[0].cellX = 1; // Inky
                                pookie[0].cellY = 17;
                                pookie[0].x = 72 + (pookie[0].cellX) * mazeCellWidth;
                                pookie[0].y = 48 + (18 - pookie[0].cellY) * mazeCellWidth;
                                pookie[0].flagRight = true;
                                pookie[0].speed = diffSpeed;
                            }
                            else if (i == 1)
                            {
                                pookie[1].cellX = 11; // Blinky
                                pookie[1].cellY = 17;
                                pookie[1].x = 72 + (pookie[1].cellX) * mazeCellWidth;
                                pookie[1].y = 48 + (18 - pookie[1].cellY) * mazeCellWidth;
                                pookie[1].flagUp = true;
                                pookie[1].speed = diffSpeed;
                            }
                            else if (i == 2)
                            {
                                pookie[2].cellX = 20; // Pinky
                                pookie[2].cellY = 17;
                                pookie[2].x = 72 + (pookie[2].cellX) * mazeCellWidth;
                                pookie[2].y = 48 + (18 - pookie[2].cellY) * mazeCellWidth;
                                pookie[2].flagRight = true;
                                pookie[2].speed = diffSpeed;
                            }
                            else if (i == 3)
                            {

                                pookie[3].cellX = 34; // Clyde
                                pookie[3].cellY = 17;
                                pookie[3].x = 72 + (pookie[3].cellX) * mazeCellWidth;
                                pookie[3].y = 48 + (18 - pookie[3].cellY) * mazeCellWidth;
                                pookie[3].flagRight = true;
                                pookie[3].speed = diffSpeed;
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
                                pookie[0].flagRight = true;
                                pookie[0].speed = diffSpeed;
                            }
                            else if (i == 1)
                            {
                                pookie[1].cellX = 12; // Blinky
                                pookie[1].cellY = 19;
                                pookie[1].x = 72 + (pookie[1].cellX) * mazeCellWidth;
                                pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
                                pookie[1].flagUp = true;
                                pookie[1].speed = diffSpeed;
                            }
                            else if (i == 2)
                            {
                                pookie[2].cellX = 20; // Pinky
                                pookie[2].cellY = 19;
                                pookie[2].x = 72 + (pookie[2].cellX) * mazeCellWidth;
                                pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
                                pookie[2].flagRight = true;
                                pookie[2].speed = diffSpeed;
                            }
                            else if (i == 3)
                            {
                                pookie[3].cellX = 35; // Clyde
                                pookie[3].cellY = 19;
                                pookie[3].x = 72 + (pookie[3].cellX) * mazeCellWidth;
                                pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
                                pookie[3].flagRight = true;
                                pookie[3].speed = diffSpeed;
                            }
                        }
                    }
                }
            }
        }
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if (playingstart)
    {
        if (key == GLUT_KEY_LEFT)
        {

            if (!(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth))
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.upCount = false;
                pac.leftCount = true;
            }
            else
            {
                pac.smoothRight = false;
                pac.smoothLeft = true;
                pac.smoothDown = false;
                pac.smoothUp = false;
            }
        }
        if (key == GLUT_KEY_RIGHT)
        {
            if (!(pac.x % mazeCellWidth) && !(pac.y % mazeCellWidth))
            {
                pac.downCount = false;
                pac.upCount = false;
                pac.leftCount = false;
                pac.rightCount = true;
            }
            else
            {
                pac.smoothRight = true;
                pac.smoothLeft = false;
                pac.smoothDown = false;
                pac.smoothUp = false;
            }
        }
        if (key == GLUT_KEY_DOWN)
        {
            if (!(pac.y % mazeCellWidth) && !(pac.x % mazeCellWidth))
            {
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = false;
                pac.downCount = true;
            }
            else
            {
                pac.smoothRight = false;
                pac.smoothLeft = false;
                pac.smoothDown = true;
                pac.smoothUp = false;
            }
        }
        if (key == GLUT_KEY_UP)
        {
            if (!(pac.y % mazeCellWidth) && !(pac.x % mazeCellWidth))
            {
                pac.downCount = false;
                pac.rightCount = false;
                pac.leftCount = false;
                pac.upCount = true;
            }
            else
            {
                pac.smoothRight = false;
                pac.smoothLeft = false;
                pac.smoothDown = false;
                pac.smoothUp = true;
            }
        }
    }
}
void pacinitialcord()
{
    if (selected == 1 || selected == 2)
    {
        cellX = 9;
        cellY = 19;
        pac.x = 168 + (cellX)*mazeCellWidth;
        pac.y = 48 + (20 - cellY) * mazeCellWidth;

        pac.downCount = false;
        pac.rightCount = false;
        pac.upCount = false;
        pac.leftCount = false;
    }
    else if (selected == 3)
    {
        cellX = 1;
        cellY = 1;
        pac.x = 72 + (cellX)*mazeCellWidth;
        pac.y = 48 + (18 - cellY) * mazeCellWidth;

        pac.downCount = false;
        pac.rightCount = false;
        pac.upCount = false;
        pac.leftCount = false;
    }
    else if (selected == 4)
    {
        cellX = 1;
        cellY = 1;
        pac.x = 72 + (cellX)*mazeCellWidth;
        pac.y = 48 + (20 - cellY) * mazeCellWidth;

        pac.downCount = false;
        pac.rightCount = false;
        pac.upCount = false;
        pac.leftCount = false;
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
        pookie[0].flagRight = true;
        pookie[0].speed = diffSpeed;

        pookie[1].cellX = 10; // Blinky
        pookie[1].cellY = 9;
        pookie[1].x = 168 + (pookie[1].cellX) * mazeCellWidth;
        pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
        pookie[1].flagUp = true;
        pookie[1].speed = diffSpeed;

        pookie[2].cellX = 10; // Pinky
        pookie[2].cellY = 9;
        pookie[2].x = 168 + (pookie[2].cellX) * mazeCellWidth;
        pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
        pookie[2].flagRight = true;
        pookie[2].speed = diffSpeed;

        pookie[3].cellX = 11; // Clyde
        pookie[3].cellY = 9;
        pookie[3].x = 168 + (pookie[3].cellX) * mazeCellWidth;
        pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
        pookie[3].flagRight = true;
        pookie[3].speed = diffSpeed;
    }
    else if (selected == 2)
    {
        pookie[0].cellX = 9; // Inky
        pookie[0].cellY = 8;
        pookie[0].x = 168 + (pookie[0].cellX) * mazeCellWidth;
        pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
        pookie[0].flagRight = true;
        pookie[0].speed = diffSpeed;

        pookie[1].cellX = 10; // Blinky
        pookie[1].cellY = 8;
        pookie[1].x = 168 + (pookie[1].cellX) * mazeCellWidth;
        pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
        pookie[1].flagUp = true;
        pookie[1].speed = diffSpeed;

        pookie[2].cellX = 10; // Pinky
        pookie[2].cellY = 8;
        pookie[2].x = 168 + (pookie[2].cellX) * mazeCellWidth;
        pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
        pookie[2].flagRight = true;
        pookie[2].speed = diffSpeed;

        pookie[3].cellX = 11; // Clyde
        pookie[3].cellY = 8;
        pookie[3].x = 168 + (pookie[3].cellX) * mazeCellWidth;
        pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
        pookie[3].flagRight = true;
        pookie[3].speed = diffSpeed;
    }
    else if (selected == 3)
    {
        pookie[0].cellX = 1; // Inky
        pookie[0].cellY = 17;
        pookie[0].x = 72 + (pookie[0].cellX) * mazeCellWidth;
        pookie[0].y = 48 + (18 - pookie[0].cellY) * mazeCellWidth;
        pookie[0].flagRight = true;
        pookie[0].speed = diffSpeed;

        pookie[1].cellX = 11; // Blinky
        pookie[1].cellY = 17;
        pookie[1].x = 72 + (pookie[1].cellX) * mazeCellWidth;
        pookie[1].y = 48 + (18 - pookie[1].cellY) * mazeCellWidth;
        pookie[1].flagUp = true;
        pookie[1].speed = diffSpeed;

        pookie[2].cellX = 20; // Pinky
        pookie[2].cellY = 17;
        pookie[2].x = 72 + (pookie[2].cellX) * mazeCellWidth;
        pookie[2].y = 48 + (18 - pookie[2].cellY) * mazeCellWidth;
        pookie[2].flagRight = true;
        pookie[2].speed = diffSpeed;

        pookie[3].cellX = 34; // Clyde
        pookie[3].cellY = 17;
        pookie[3].x = 72 + (pookie[3].cellX) * mazeCellWidth;
        pookie[3].y = 48 + (18 - pookie[3].cellY) * mazeCellWidth;
        pookie[3].flagRight = true;
        pookie[3].speed = diffSpeed;
    }
    else if (selected == 4)
    {
        pookie[0].cellX = 1; // Inky
        pookie[0].cellY = 19;
        pookie[0].x = 72 + (pookie[0].cellX) * mazeCellWidth;
        pookie[0].y = 48 + (20 - pookie[0].cellY) * mazeCellWidth;
        pookie[0].flagRight = true;
        pookie[0].speed = diffSpeed;

        pookie[1].cellX = 12; // Blinky
        pookie[1].cellY = 19;
        pookie[1].x = 72 + (pookie[1].cellX) * mazeCellWidth;
        pookie[1].y = 48 + (20 - pookie[1].cellY) * mazeCellWidth;
        pookie[1].flagUp = true;
        pookie[1].speed = diffSpeed;

        pookie[2].cellX = 20; // Pinky
        pookie[2].cellY = 19;
        pookie[2].x = 72 + (pookie[2].cellX) * mazeCellWidth;
        pookie[2].y = 48 + (20 - pookie[2].cellY) * mazeCellWidth;
        pookie[2].flagRight = true;
        pookie[2].speed = diffSpeed;

        pookie[3].cellX = 35; // Clyde
        pookie[3].cellY = 19;
        pookie[3].x = 72 + (pookie[3].cellX) * mazeCellWidth;
        pookie[3].y = 48 + (20 - pookie[3].cellY) * mazeCellWidth;
        pookie[3].flagRight = true;
        pookie[3].speed = diffSpeed;
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
            startintro = false;
            mainmenu = true;
            iPauseTimer(0);
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
            congrats = false;
            mainmenu = true;
            iPauseAll();
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
        if (backgroundselectorc > 499)
        {
            backgroundselectorc = 499;
            iPauseTimer(0);
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
void deathScene()
{
    if (pacdead)
    {
        deadSceneCount++;
        if (deadSceneCount > 11)
        {
            deadSceneCount = 0;
            pacdead = false;

            pacmanlife--;
            pacinitialcord();
            pookieinitialcoordinate();
            blueGhost = false;
            pookie[0].blueOn = false;
            pookie[1].blueOn = false;
            pookie[2].blueOn = false;
            pookie[3].blueOn = false;
            Sleep(800);
            if (pacmanlife == 0)
            {
                chase = false;
                scatter = true;
                DataAnalysis();
                congrats = true;
            }

            iResumeTimer(3);
            iResumeTimer(2);
        }
    }
}
void DataAnalysis()
{

    FILE *fp;
    char ch;
    line = 0;
    if (score != 0)
    {
        // Sub write
        fp = fopen("score.txt", "a");
        fprintf(fp, "%s %d\n", playername, score);
        fclose(fp);
    }

    fp = fopen("Score.txt", "r");
    while (fscanf(fp, "%c", &ch) == 1)
    {
        if (ch == '\n')
            line++;
    }
    fclose(fp);
    // Store data
    fp = fopen("Score.txt", "r");
    name = (char **)malloc(sizeof(char *) * line);
    point = (int *)malloc(sizeof(int) * line);
    for (int i = 0; i < line; i++)
    {
        name[i] = (char *)malloc(sizeof(char) * 20);
        fscanf(fp, " %s %d", name[i], &point[i]);
    }
    fclose(fp);
    // Sort data
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < line; j++)
        {
            if (point[i] > point[j])
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
    fp = fopen("highScore.txt", "w");
    for (int i = 0; i < line; i++)
    {
        fprintf(fp, "%s %d\n", name[i], point[i]);
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    DataAnalysis();
    glutInit(&argc, argv);
    corrdinatestore1();
    corrdinatestore2();
    corrdinatestore3();
    corrdinatestore4();

    iSetTimer(10, collisioncheck);

    iSetTimer(1300, bluetimecheck);

    iSetTimer(20, pookiemovement);
    iSetTimer(10, pacmanmovement);

    iSetTimer(20, introchange);
    iSetTimer(20, scoreshow);
    iSetTimer(10, background);
    iSetTimer(20, exitSequence);
    iSetTimer(20, level);
    iSetTimer(120, deathScene);
    iInitialize(1200, 675, "PACMAN");
    return 0;
}
