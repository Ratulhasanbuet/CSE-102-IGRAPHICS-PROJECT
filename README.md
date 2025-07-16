<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>PAC-MAN: Retro Reimagined</title>
  <style>
    body {
      background-color: #121212;
      color: #f0f0f0;
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      line-height: 1.6;
      max-width: 960px;
      margin: 0 auto;
      padding: 20px;
    }
    h1, h2, h3 {
      color: #ffcc00;
      margin-top: 1.5rem;
    }
    h1 {
      text-align: center;
      margin-bottom: 0.5rem;
    }
    h2 {
      border-bottom: 2px solid #ffcc00;
      padding-bottom: 0.3rem;
      margin-bottom: 1rem;
    }
    nav {
      text-align: center;
      margin: 1rem 0;
    }
    nav a {
      color: #00ffff;
      text-decoration: none;
      margin: 0 0.75rem;
      font-weight: bold;
    }
    nav a:hover {
      text-decoration: underline;
    }
    table {
      width: 100%;
      border-collapse: collapse;
      margin: 1rem 0;
      background-color: #1e1e1e;
    }
    th, td {
      border: 1px solid #444;
      padding: 0.6rem 0.8rem;
      text-align: left;
    }
    th {
      background-color: #2a2a2a;
      color: #00ffff;
    }
    tr:nth-child(even) {
      background-color: #202020;
    }
    ul, ol {
      margin: 0.5rem 0 0.5rem 1.5rem;
    }
    footer {
      text-align: center;
      margin-top: 2rem;
      font-size: 0.9rem;
      color: #888;
    }
  </style>
</head>
<body>

  <h1>PAC-MAN: Retro Reimagined</h1>
  <p style="text-align: center; font-style: italic; color: #ccc;">
    A tribute to the timeless classic, built from scratch in C with <code>iGraphics.h</code>
  </p>

  <nav>
    <a href="#authors">Authors</a> |
    <a href="#overview">Overview</a> |
    <a href="#mechanics">Mechanics</a> |
    <a href="#ui">UI & Menus</a> |
    <a href="#mazes">Mazes & Themes</a> |
    <a href="#difficulty">Difficulty</a> |
    <a href="#scoring">Scoring</a> |
    <a href="#ghosts">Ghost AI</a> |
    <a href="#code">Code</a>
  </nav>

  <section id="authors">
    <h2>Authors & Credits</h2>
    <ul>
      <li><strong>Md Ratul Hasan</strong> — CSE'24</li>
      <li><strong>Hasibul Islam</strong> — CSE'24</li>
      <li>Guided by Abdur Rafi</li>
    </ul>
  </section>

  <section id="overview">
    <h2>Game Overview</h2>
    <ul>
      <li>Four distinct maze layouts</li>
      <li>Eight brick-pattern designs</li>
      <li>Six immersive background themes</li>
      <li>Four challenge tiers (Easy → Extreme)</li>
      <li>Up to 6 ghosts (adds Donky & Rinky on higher levels)</li>
      <li>Persistent local high-score board (top 6)</li>
    </ul>
  </section>

  <section id="mechanics">
    <h2>Gameplay Mechanics</h2>
    <h3>Objective</h3>
    <ul>
      <li>Eat all pellets</li>
      <li>Avoid ghosts</li>
      <li>Clear each maze</li>
    </ul>
    <h3>Controls</h3>
    <ul>
      <li>Arrow Keys → Move Pac-Man</li>
      <li>ENTER → Confirm menu/name entry</li>
      <li>ESC / Q → Pause or exit to main menu</li>
      <li>Mouse Click → UI navigation</li>
    </ul>
    <h3>Lives & Blue Mode</h3>
    <ul>
      <li>Start with 3 lives</li>
      <li>Gain extra life via rare fruits</li>
      <li>Lose life on collision (unless ghost is blue)</li>
      <li>Blue (Frightened) mode lasts ~10 seconds</li>
    </ul>
  </section>

  <section id="ui">
    <h2>UI & Menus</h2>
    <h3>Main Menu</h3>
    <ul>
      <li>Play: Start game</li>
      <li>High Scores: Show top 6</li>
      <li>Settings: Sound & maze selection</li>
      <li>Difficulty: Adjust ghost/Pac speeds</li>
      <li>Credits & Rules: View docs</li>
      <li>Quit: Exit with animation</li>
    </ul>
    <h3>Settings Screen</h3>
    <ul>
      <li>🔊 Sound ON / OFF</li>
      <li>🧩 Maze Layout selector</li>
      <li>🔙 Back button</li>
    </ul>
    <h3>Name Entry</h3>
    <ul>
      <li>Keyboard input</li>
      <li>Real-time validation</li>
      <li>Stores player name for high scores</li>
    </ul>
  </section>

  <section id="mazes">
    <h2>Mazes & Themes</h2>
    <h3>Brick Designs (8)</h3>
    <ol>
      <li>Spiral</li>
      <li>Phantom</li>
      <li>Nebula</li>
      <li>Pixel Pulse</li>
      <li>Psi</li>
      <li>Echo</li>
      <li>Crack</li>
      <li>Spectral</li>
    </ol>
    <h3>Background Themes (6)</h3>
    <ul>
      <li>Classic Grid</li>
      <li>Neon Pulse</li>
      <li>Ice Circuit</li>
      <li>Inferno Zone</li>
      <li>Retro Forest</li>
      <li>Cosmic Drift</li>
    </ul>
  </section>

  <section id="difficulty">
    <h2>Difficulty & Progression</h2>
    <h3>Modes</h3>
    <table>
      <tr>
        <th>Mode</th>
        <th>Ghost Speed</th>
        <th>Pac Speed</th>
        <th>Behavior</th>
      </tr>
      <tr>
        <td>Easy 🟢</td>
        <td>2</td>
        <td>3</td>
        <td>Simple chase</td>
      </tr>
      <tr>
        <td>Medium 🟡</td>
        <td>3</td>
        <td>3</td>
        <td>Standard chase</td>
      </tr>
      <tr>
        <td>Hard 🔵</td>
        <td>4</td>
        <td>3</td>
        <td>Advanced prediction</td>
      </tr>
      <tr>
        <td>Extreme 🔴</td>
        <td>4</td>
        <td>4</td>
        <td>Blast mode & chaining</td>
      </tr>
    </table>
    <h3>Maze Levels</h3>
    <table>
      <tr>
        <th>Level</th>
        <th>Size</th>
        <th>Pellets</th>
        <th>Ghosts</th>
        <th>Features</th>
      </tr>
      <tr>
        <td>1</td>
        <td>21×21</td>
        <td>226</td>
        <td>4</td>
        <td>Classic layout</td>
      </tr>
      <tr>
        <td>2</td>
        <td>21×21</td>
        <td>236</td>
        <td>4</td>
        <td>Challenging twists</td>
      </tr>
      <tr>
        <td>3</td>
        <td>19×36</td>
        <td>362</td>
        <td>6</td>
        <td>Adds Donky & Rinky</td>
      </tr>
      <tr>
        <td>4</td>
        <td>21×40</td>
        <td>454</td>
        <td>6</td>
        <td>Blast mode ghosts</td>
      </tr>
    </table>
  </section>

  <section id="scoring">
    <h2>Scoring & Bonuses</h2>
    <table>
      <tr>
        <th>Action</th>
        <th>Points</th>
      </tr>
      <tr>
        <td>Regular Pellet</td>
        <td>+10</td>
      </tr>
      <tr>
        <td>Power Pellet</td>
        <td>+50</td>
      </tr>
      <tr>
        <td>Fruit Bonus</td>
        <td>+1000 / +1 Life (rare)</td>
      </tr>
      <tr>
        <td>Blue Ghosts (combo)</td>
        <td>+100 → +300 → +900 → +2700</td>
      </tr>
      <tr>
        <td>Maze Completion</td>
        <td>+2000</td>
      </tr>
    </table>
    <p>Fruits spawn every 600 ticks at random open cells. 16 types, some grant extra life.</p>
  </section>

  <section id="ghosts">
    <h2>Ghost AI & Behaviors</h2>
    <table>
      <tr>
        <th>Mode</th>
        <th>Description</th>
      </tr>
      <tr>
        <td>Scatter</td>
        <td>Patrol preset corners</td>
      </tr>
      <tr>
        <td>Chase</td>
        <td>Dynamic pursuit</td>
      </tr>
      <tr>
        <td>Blast</td>
        <td>High aggression</td>
      </tr>
      <tr>
        <td>Blue</td>
        <td>Vulnerable & fleeing</td>
      </tr>
    </table>
    <ul>
      <li><strong>Blinky</strong> – Direct pursuit</li>
      <li><strong>Pinky</strong> – Predicts 4 cells ahead</li>
      <li><strong>Inky</strong> – Trails & cuts off</li>
      <li><strong>Clyde</strong> – Ambushes vertically</li>
      <li><strong>Donky & Rinky</strong> – Unpredictable advanced chasers</li>
    </ul>
  </section>

  <section id="code">
    <h2>Code Structure</h2>
    <h3>Data Structures</h3>
    <ul>
      <li><code>pacmove</code>: Pac-Man’s position, direction flags, animation states</li>
      <li><code>ghost</code>: Ghost AI state, position, speed, vulnerability flags</li>
      <li>Maze arrays (`maze1[][]`…`maze4[][]`)</li>
      <li>Coordinate maps (`mapX/Y[][]`)</li>
    </ul>
    <h3>Core Functions</h3>
    <ul>
      <li><code>pacmanmovement()</code>: Buffered input & movement</li>
      <li><code>pookiemovement()</code>: Global ghost AI & pathfinding</li>
      <li><code>collisioncheck()</code>: Pellets, ghosts, power-pellet effects</li>
      <li><code>drawMazeX()</code>: Renders walls via <code>iShowImage</code></li>
      <li><code>drawFoodAndPowerPellet()</code>: Draws pellets & fruits</li>
      <li><code>bluetimecheck()</code>: Manages Blue mode timer</li>
      <li><code>directionGenerator()</code>: Targets per ghost mode</li>
      <li><code>DataAnalysis()</code>: High-score file I/O</li>
    </ul>
  </section>

  <footer>
    Made by Ratul 🎯 | Powered by precision, obsession & <code>iGraphics</code> ❤️<br/>
    Let’s make arcades great again!
  </footer>
</body>
</html>
