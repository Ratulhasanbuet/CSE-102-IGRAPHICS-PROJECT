<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>PACMAN EXTREME - Complete Guide</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #0d0d0d;
      color: #f2f2f2;
      line-height: 1.6;
      padding: 40px;
      max-width: 1000px;
      margin: auto;
    }
    h1, h2, h3 {
      color: #ffdd00;
      text-align: center;
    }
    h2 {
      border-bottom: 2px solid #ffdd00;
      padding-bottom: 5px;
      margin-top: 40px;
    }
    h3 {
      margin-top: 30px;
    }
    table {
      width: 100%;
      border-collapse: collapse;
      margin: 20px 0;
      background-color: #1a1a1a;
    }
    th, td {
      border: 1px solid #444;
      padding: 10px;
      text-align: left;
    }
    th {
      background-color: #333;
    }
    tr:nth-child(even) {
      background-color: #222;
    }
    code {
      background-color: #222;
      padding: 3px 6px;
      border-radius: 4px;
      color: #00ffcc;
    }
    ul {
      margin-left: 20px;
    }
    details {
      margin: 10px 0;
      padding: 10px;
      background: #1a1a1a;
      border: 1px solid #333;
      border-radius: 6px;
    }
    summary {
      cursor: pointer;
      font-weight: bold;
      color: #ffdd00;
    }
    .mindmap ul {
      list-style-type: none;
      padding-left: 20px;
      border-left: 2px dashed #555;
    }
    .mindmap li {
      margin: 6px 0;
      position: relative;
    }
    .mindmap li::before {
      content: '✦';
      position: absolute;
      left: -15px;
      color: #ffdd00;
      font-size: 0.9em;
    }
    footer {
      margin-top: 40px;
      text-align: center;
      font-size: 0.9em;
      color: #888;
    }
    nav ul {
      list-style: none;
      text-align: center;
      margin-bottom: 30px;
      padding: 0;
    }
    nav li {
      display: inline-block;
      margin: 0 12px;
    }
    nav a {
      color: #00ffff;
      text-decoration: none;
      font-weight: bold;
    }
    nav a:hover {
      text-decoration: underline;
    }
  </style>
</head>
<body>

  <h1>PACMAN EXTREME</h1>
  <h2>🎮 Game Rules, Mechanics & Developer Guide</h2>

  <nav>
    <ul>
      <li><a href="#objective">Objective</a></li>
      <li><a href="#controls">Controls</a></li>
      <li><a href="#scoring">Scoring</a></li>
      <li><a href="#ghosts">Ghosts</a></li>
      <li><a href="#fruits">Fruits</a></li>
      <li><a href="#lives">Lives</a></li>
      <li><a href="#mazes">Mazes</a></li>
      <li><a href="#menu">Menu</a></li>
      <li><a href="#code">Code Structure</a></li>
      <li><a href="#mindmap">Mind Map</a></li>
      <li><a href="#tips">Tips</a></li>
    </ul>
  </nav>

  <section id="objective">
    <h3>🎯 Objective</h3>
    <ul>
      <li>Eat all dots and power-pellets to clear the maze</li>
      <li>Outmaneuver ghosts using tactics and timing</li>
      <li>Collect fruits for score boosts and extra lives</li>
      <li>Advance through increasingly difficult mazes</li>
    </ul>
  </section>

  <section id="controls">
    <h3>🧠 Controls</h3>
    <ul>
      <li><code>Arrow Keys</code> – Move Pac-Man</li>
      <li><code>P</code> – Pause/Resume</li>
      <li><code>ENTER</code> – Confirm selections</li>
      <li><code>ESC / Q</code> – Quit to Menu</li>
    </ul>
  </section>

  <section id="scoring">
    <h3>💯 Scoring System</h3>
    <table>
      <tr><th>Action</th><th>Points</th></tr>
      <tr><td>Eat Regular Dot</td><td>+10</td></tr>
      <tr><td>Eat Power Pellet</td><td>+50</td></tr>
      <tr><td>Eat Fruit</td><td>+1000 or Extra Life</td></tr>
      <tr><td>Eat Blue Ghosts</td><td>+100 → +300 → +900 → +2700</td></tr>
      <tr><td>Complete Maze</td><td>+2000 Bonus</td></tr>
    </table>
  </section>

  <section id="ghosts">
    <h3>👻 Ghost Behavior</h3>
    <table>
      <tr><th>Mode</th><th>Description</th></tr>
      <tr><td>Scatter</td><td>Ghosts retreat to preset corners</td></tr>
      <tr><td>Chase</td><td>Smart tracking with individual logic</td></tr>
      <tr><td>Blast</td><td>Maximum aggression (level-triggered)</td></tr>
      <tr><td>Blue (Frightened)</td><td>Slow vulnerable mode after power-pellet</td></tr>
    </table>
    <ul>
      <li><strong>Blinky</strong> – Direct hunter</li>
      <li><strong>Pinky</strong> – Predicts forward movement</li>
      <li><strong>Clyde</strong> – Alternates movement logic</li>
      <li><strong>Inky</strong> – Trails behind and cuts off</li>
      <li><strong>Rinky & Donky</strong> – Appear in Maze 3 & 4 with advanced unpredictable behavior</li>
    </ul>
  </section>

  <section id="fruits">
    <h3>🍓 Fruit Mechanics</h3>
    <ul>
      <li>Spawn at random positions every 60 seconds</li>
      <li>Provide <code>+1000</code> points or an extra life</li>
      <li>Vanish if not collected quickly</li>
      <li>Drawn using sprites and flagged in pellet array</li>
    </ul>
  </section>

  <section id="lives">
    <h3>❤️ Lives</h3>
    <ul>
      <li>Start with 3 lives</li>
      <li>Gain extra lives by catching rare fruits</li>
      <li>Lose a life if hit by ghost (unless ghost is blue)</li>
      <li>Game over when lives reach zero</li>
    </ul>
  </section>

  <section id="mazes">
    <h3>🌌 Maze Progression</h3>
    <table>
      <tr><th>Maze</th><th>Size</th><th>Dots</th><th>Ghosts</th><th>Notes</th></tr>
      <tr><td>Maze 1</td><td>21×21</td><td>226</td><td>4</td><td>Beginner Level</td></tr>
      <tr><td>Maze 2</td><td>21×21</td><td>236</td><td>4</td><td>Intermediate</td></tr>
      <tr><td>Maze 3</td><td>19×36</td><td>362</td><td>6</td><td>Donky & Rinky appear</td></tr>
      <tr><td>Maze 4</td><td>21×40</td><td>454</td><td>6</td><td>Expert difficulty</td></tr>
    </table>
  </section>

  <section id="menu">
    <h3>🕹️ Menu Options</h3>
   <table> <tr><th>Option</th><th>Function</th></tr> <tr><td>Play</td><td>Starts the game instantly</td></tr> <tr><td>High Score</td><td>Shows leaderboard saved in <code>highScore.txt</code></td></tr> <tr><td>Settings</td><td>Adjust sound, backgrounds, and maze layout</td></tr> <tr><td>Difficulty</td><td>Controls ghost speed and Pac-Man animation rate</td></tr> <tr><td>Credits & Rules</td><td>Slideshow of developer info and gameplay mechanics</td></tr> <tr><td>Quit</td><td>Exits with a farewell animation</td></tr> </table> </section>

<section id="code"> <h3>🧬 Code Structure & Key Files</h3> <details> <summary>🔧 Game Engine Components</summary> <ul> <li><strong>iGraphics.h</strong> – Framework for graphics, sound, sprite, and input</li> <li><strong>pacman.c / iMain.cpp</strong> – Core logic for movement, rendering, collisions</li> <li><strong>foodXcor[][]</strong> – Stores pellets, power-pellets, fruits</li> <li><strong>pookie[6]</strong> – Ghost movement logic structs</li> <li><strong>corrdinatestoreX()</strong> – Translates grid cells to pixel coordinates</li> <li><strong>collisioncheck()</strong> – Pellet eating, ghost–player interaction</li> </ul> </details>

<details> <summary>🧪 Timers & Animation</summary> <ul> <li>Set via <code>iSetTimer()</code> — ghost animation, mouth opening, score updates</li> <li><code>iAnimateSprite()</code> used to cycle through Pac-Man frames</li> <li>Ghost flashing is triggered during final seconds of “blue” mode</li> </ul> </details>

<details> <summary>💾 High Score System</summary> <pre><code> void DataAnalysis() { // Read scores from highScore.txt // Sort descending // Save top 5 players & scores } </code></pre> </details>

<details> <summary>🌍 Map Drawing</summary> <ul> <li>Four distinct mazes, rendered by <code>drawMazeX()</code></li> <li>Pellets drawn conditionally using flags in food array</li> </ul> </details> </section>

<section id="mindmap"> <h3>🧠 Game Mind Map</h3> <div class="mindmap"> <ul> <li>PACMAN EXTREME <ul> <li>Gameplay <ul> <li>Controls</li> <li>Pellet & Power Logic</li> <li>Ghost Modes</li> </ul> </li> <li>Characters <ul> <li>Pac-Man</li> <li>Ghosts: Blinky, Pinky, Inky, Clyde, Donky, Rinky</li> </ul> </li> <li>Assets <ul> <li>Fruit Sprites</li> <li>Ghost Frames</li> <li>Sound: MP3 / OGG support</li> </ul> </li> <li>Game Engine <ul> <li>Movement</li> <li>Collision</li> <li>Animation</li> </ul> </li> <li>Features <ul> <li>Difficulty Modes</li> <li>Maze Selection</li> <li>High Scores</li> <li>Pause/Resume</li> </ul> </li> </ul> </li> </ul> </div> </section>

<section id="tips"> <h3>🧠 Pro Tips</h3> <ul> <li>Chain ghost captures in blue mode for exponential score boosts</li> <li>Use corners and tunnels to bait ghost paths during scatter mode</li> <li>Learn ghost personalities — Blinky always hunts directly, Pinky tries to ambush</li> <li>Always grab fruits before they vanish — they’re timed!</li> <li>Pause the game smartly to plan your next move</li> <li>Rotate mazes by difficulty and memorize fruit spawn zones</li> </ul> </section>

<footer> <p>© 2025 PACMAN EXTREME • Developed with Modern-iGraphics • All gameplay and AI logic documented.</p> </footer>

</body> </html>