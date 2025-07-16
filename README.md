Filename: README.txt

Pac-Man Game Documentation
===========================

1. Overview
-----------
This is a full-featured Pac-Man clone built in C using iGraphics.h. It includes:
- Intro animation and menus
- Level selection (4 maze layouts)
- Difficulty settings influencing ghost speed and AI modes
- In-game pause, background selector, high-score, settings, credits, rules
- Scoring, lives, fruits, power-pellets, ghost AI modes (scatter, chase, frightened)

2. How to Play
--------------
1. Run the game executable.
2. Watch the intro slideshow, then press Enter to enter the main menu.
3. Navigate menus with mouse:
   - Play: enter name, select level.
   - Difficulty: choose ghost speed & AI behavior.
   - Settings: toggle sound, pick maze skin.
   - High Score, Credits, Rules, Quit.
4. Controls in game:
   - Arrow keys to move Pac-Man.
   - Click pause icon or press ESC to pause.
   - Mouse: resume, change background, return to menu.
5. Objective:
   - Eat all pellets and fruits to clear the level.
   - Collect power-pellets to turn ghosts blue and earn bonus points.
   - Avoid ghosts unless they are frightened.
   - Survive with 3 lives; extra lives can appear as fruits.

3. Main Features
----------------
- **Menus & Intro**: Animated slideshow, mouse-driven buttons.
- **Levels**: Four distinct map arrays (21×21, 21×21, 19×36, 21×40).
- **Ghost AI**:
  - Scatter: ghosts roam fixed corners.
  - Chase: predictive targeting per ghost type.
  - Frightened: slow ghosts turn blue; can be eaten.
- **Scoring**:
  - Dots: 10 points.
  - Fruits: up to 1000 points.
  - Ghosts: 200, 600, 1800… escalating per successive eat.
- **File I/O**:
  - Records and sorts high scores in “highScore.txt”.
  - Reads/writes player names and scores.
- **Timers**: Uses iSetTimer for game loop, animations, ghost AI, intro, etc.

4. Code Structure
-----------------

4.1 Data Structures
   - `struct move` for Pac-Man: position, direction flags, animation indices.
   - `struct ghost` for each enemy: position, speed, direction flags, AI distances.
   - Arrays for maze layouts: `maze1[][]`, `maze2[][]`, `maze3[][]`, `maze4[][]`.
   - Coordinate lookup: `mapX[][]`, `mapY[][]` for pixel positions.
   - Food arrays: `foodXcor[][2]`, `foodYcor[]`, status flags.

4.2 Core Functions
   - `main()`: initialization, timers, event loop.
   - `iDraw()`: draws everything based on current state flags.
   - `pacmanmovement()`: updates Pac-Man position & collision.
   - `pookiemovement()`: updates ghost positions with AI logic.
   - `collisioncheck()`: pellet consumption, fruit spawn, life/ghost collisions.
   - `DataAnalysis()`: reads, sorts, and writes high-score data.

4.3 Rendering
   - `drawMazeN()`: renders walls via `iShowImage` for each cell.
   - `drawFoodAndPowerPellet()`: draws dots, power-pellets, fruits.
   - Image arrays hold file paths for all sprites and backgrounds.

4.4 Input Handling
   - `iKeyboard()`: text entry for player name, menu shortcuts.
   - `iSpecialKeyboard()`: arrow keys for movement.
   - `iMouse()`, `iMouseMove()`: menu button hover and clicks.

4.5 Timers & Flow Control
   - Intro slideshow timer (`introchange`).
   - Ghost/animation timers: movement loops, frightened mode.
   - Pause/resume functions to stop all timers when paused.

4.6 File I/O & High Score
   - Appends new scores to “score.txt” on level end.
   - Reads back, sorts descending, writes top entries to “highScore.txt”.

4.7 Asset Organization
   - Separate folders for each sprite set:
     - `pacman/`, `inky/`, `blinky/`, `pinky/`, `clyde/`, `donky/`, `rinky/`
   - UI images: `introimage/`, `menu image/`, `settingsimage/`, etc.
   - Backgrounds: `bg/`, `slbg/`.
   - All file paths stored in C arrays for easy theme switching.

5. Configuration
----------------
- `mazeCellWidth` and `mazeCellHeight` define grid cell size in pixels.
- `diffSpeed` sets ghost movement speed per difficulty.
- `fruitTimeInterval` controls interval between fruit spawns.
- Sound toggled via a boolean `soundOn`.

6. Controls Summary
-------------------
- Arrow keys: move Pac-Man.
- Mouse:
  - Click menu options.
  - Click pause icon.
  - In pause screen: resume, change background, return to menu.
- Enter: confirm in text input and intro screen.
- ESC: cancel name entry.

Enjoy customizing, extending, and playing your Pac-Man clone!
