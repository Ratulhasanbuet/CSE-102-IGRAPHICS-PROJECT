<!-- Filename: index.html -->
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Pac-Man Game Documentation</title>
  <link rel="stylesheet" href="styles.css">
</head>
<body>
  <header>
    <h1>Pac-Man Game Documentation</h1>
  </header>
  <nav>
    <ul>
      <li><a href="#overview">Overview</a></li>
      <li><a href="#how-to-play">How to Play</a></li>
      <li><a href="#features">Main Features</a></li>
      <li><a href="#code-structure">Code Structure</a></li>
      <li><a href="#configuration">Configuration</a></li>
      <li><a href="#controls">Controls</a></li>
    </ul>
  </nav>

  <section id="overview">
    <h2>1. Overview</h2>
    <p>This is a full-featured Pac-Man clone built in C using <code>iGraphics.h</code>. It includes intro animation, menus, four levels, difficulty settings, and more.</p>
  </section>

  <section id="how-to-play">
    <h2>2. How to Play</h2>
    <ol>
      <li>Run the game executable.</li>
      <li>Press Enter to skip the intro and open the main menu.</li>
      <li>Use the mouse to navigate:
        <ul>
          <li>Play &rarr; enter name &rarr; select level</li>
          <li>Difficulty &rarr; choose ghost speed & AI behavior</li>
          <li>Settings &rarr; toggle sound, pick maze theme</li>
          <li>High Score, Credits, Rules, Quit</li>
        </ul>
      </li>
      <li>In-game:
        <ul>
          <li>Arrow keys to move Pac-Man</li>
          <li>Click pause icon or press ESC to pause</li>
          <li>Collect all dots & fruits, avoid ghosts</li>
          <li>Power-pellets turn ghosts blue (vulnerable)</li>
        </ul>
      </li>
    </ol>
  </section>

  <section id="features">
    <h2>3. Main Features</h2>
    <ul>
      <li><strong>Animated Menus</strong>: Intro slideshow, mouse-driven UI.</li>
      <li><strong>Levels</strong>: Four maze layouts of varying sizes.</li>
      <li><strong>Ghost AI</strong>: Scatter, chase, frightened modes.</li>
      <li><strong>Scoring & Lives</strong>: Dots, fruits, escalating ghost bonuses.</li>
      <li><strong>High Score</strong>: Persistent file-based leaderboard.</li>
      <li><strong>Pause & Settings</strong>: Background selector, sound toggle.</li>
    </ul>
  </section>

  <section id="code-structure">
    <h2>4. Code Structure</h2>

    <h3>4.1 Data Structures</h3>
    <ul>
      <li><code>struct move</code>: Pac-Man position, flags, animation frames.</li>
      <li><code>struct ghost</code>: Ghost position, speed, AI flags, distances.</li>
      <li>Maze arrays: <code>maze1[][]</code> … <code>maze4[][]</code>.</li>
      <li>Coordinate lookup: <code>mapX[][]</code>, <code>mapY[][]</code>.</li>
    </ul>

    <h3>4.2 Core Functions</h3>
    <ul>
      <li><code>iDraw()</code>: Render loop based on state flags.</li>
      <li><code>pacmanmovement()</code>, <code>pookiemovement()</code>: Movement & collision.</li>
      <li><code>collisioncheck()</code>: Pellet eating, life/ghost interactions.</li>
      <li><code>DataAnalysis()</code>: High-score file management.</li>
    </ul>

    <h3>4.3 Rendering & Assets</h3>
    <ul>
      <li>Maze walls with <code>iShowImage</code>.</li>
      <li>Food, power pellets, fruits drawn as circles or sprites.</li>
      <li>All images stored in themed folders, loaded via arrays.</li>
    </ul>

    <h3>4.4 Input Handling</h3>
    <ul>
      <li><code>iKeyboard()</code> for text and menu shortcuts.</li>
      <li><code>iSpecialKeyboard()</code> for arrow-key movement.</li>
      <li><code>iMouse()</code> & <code>iMouseMove()</code> for menus.</li>
    </ul>

    <h3>4.5 Timers & Flow</h3>
    <ul>
      <li><code>iSetTimer</code> for animations, AI updates, intro slideshow.</li>
      <li>Pause/resume all timers on pause state.</li>
    </ul>

    <h3>4.6 File I/O & High Score</h3>
    <ul>
      <li>Appends to <code>score.txt</code>, reads/sorts, writes <code>highScore.txt</code>.</li>
    </ul>
  </section>

  <section id="configuration">
    <h2>5. Configuration</h2>
    <ul>
      <li><code>mazeCellWidth</code>: Pixel size of grid cell.</li>
      <li><code>diffSpeed</code>: Ghost speed per difficulty.</li>
      <li><code>fruitTimeInterval</code>: Fruit spawn timing.</li>
      <li><code>soundOn</code>: Boolean toggle for sound.</li>
    </ul>
  </section>

  <section id="controls">
    <h2>6. Controls</h2>
    <ul>
      <li>Arrow keys: Move Pac-Man.</li>
      <li>Mouse click: Menu and pause actions.</li>
      <li>Enter: Confirm text input and menus.</li>
      <li>ESC: Cancel name entry or pause.</li>
    </ul>
  </section>

  <footer>
    <p>Generated documentation for the Pac-Man project. Customize as needed.</p>
  </footer>
</body>
</html>
