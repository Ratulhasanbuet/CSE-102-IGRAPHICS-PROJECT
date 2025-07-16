<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>Pacman Game Documentation</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 40px;
      line-height: 1.7;
      background-color: #f4f4f4;
      color: #333;
    }
    h1, h2 {
      color: #111;
    }
    code {
      background: #eee;
      padding: 2px 4px;
      border-radius: 4px;
    }
    pre {
      background: #eee;
      padding: 10px;
      border-radius: 6px;
      overflow-x: auto;
    }
    ul {
      list-style: disc;
      margin-left: 20px;
    }
  </style>
</head>
<body>

  <h1>Pacman Game – Documentation</h1>

  <p>This is a custom-built version of the classic Pacman game, created using C with the iGraphics library. The game contains multiple mazes, ghost AIs, scoring system, power-ups, and sprite animations.</p>

  <h2>🎮 Game Features</h2>
  <ul>
    <li>Multiple playable mazes (21x21, 19x36, 21x40 formats)</li>
    <li>Custom-designed maze layouts stored in 2D arrays</li>
    <li>Pacman movement logic with smooth transitions and direction controls</li>
    <li>6 Ghost characters with movement logic and AI behaviors</li>
    <li>Food pellets, power-ups, and fruit items for score boosts</li>
    <li>Score tracking, life system, and death animation</li>
    <li>Fully animated character sprites (Pacman + Ghosts)</li>
    <li>Background customization & intro/outro scenes</li>
    <li>Menu system: Main Menu, Difficulty Selector, Maze Selector, Highscore, Credits, Rules, Pause, etc.</li>
    <li>Sound effects & visual effects (optional via <code>soundOn</code>)</li>
  </ul>

  <h2>🧱 Game Architecture</h2>

  <ul>
    <li><strong>Pacman:</strong> Position and movement handled via a <code>pacmove</code> struct</li>
    <li><strong>Ghosts:</strong> Each ghost has its own <code>ghost</code> struct instance with cell position and direction flags</li>
    <li><strong>Mazes:</strong> Defined in 2D integer arrays like <code>maze1</code>, <code>maze2</code>, <code>maze3</code>, etc.</li>
    <li><strong>Coordinate Maps:</strong> Maze cell coordinates are mapped via <code>mapXCoordinate[][]</code> arrays</li>
    <li><strong>Images:</strong> Stored in arrays such as <code>introimage[][]</code>, <code>pacmanRight[][]</code>, etc.</li>
    <li><strong>Game States:</strong> Controlled by many Boolean flags like <code>mainmenu</code>, <code>pause</code>, <code>highscore</code>, etc.</li>
    <li><strong>Player Info:</strong> Stored in <code>playername[]</code>, <code>score</code>, <code>pacmanlife</code></li>
  </ul>

  <h2>🕹️ Controls</h2>
  <ul>
    <li><strong>Arrow keys</strong> – Move Pacman</li>
    <li><strong>P</strong> – Pause Game</li>
    <li><strong>ENTER</strong> – Start Game or Resume</li>
    <li><strong>ESC</strong> – Exit game or go back</li>
  </ul>

  <h2>📦 Resources Required</h2>

  <p>Ensure you have these folders in the same directory as the binary:</p>

  <ul>
    <li><code>introimage/</code>, <code>creditsimage/</code>, <code>rules/</code>, <code>mazeDesignImage/</code></li>
    <li><code>pacman/</code>, <code>ghost/</code>, <code>fruit/</code>, <code>slbg/</code>, <code>bg/</code></li>
    <li><code>playgameintro/</code>, <code>thanksimage/</code>, <code>congrats/</code></li>
  </ul>

  <h2>🔧 Compilation & Run</h2>

  <p>Use a C compiler that supports <code>iGraphics</code> library (e.g., GCC with Windows multimedia).</p>

  <pre>
gcc iMain.cpp -o pacman -liGraphics -lwinmm
./pacman
  </pre>

  <h2>📑 Notes</h2>

  <ul>
    <li>The game uses over 500 images for animation, backgrounds, and UI</li>
    <li>Each level can be customized through the maze arrays</li>
    <li>Ghost behaviors can be extended using <code>blueOn</code>, <code>dist</code>, <code>scatter</code> flags</li>
    <li>Game logic is controlled through timing, random generators, and structured movement</li>
  </ul>

  <h2>👨‍💻 Developed By</h2>
  <p>Ratul Hasan<br>
  [Your GitHub or Email]</p>

</body>
</html>
