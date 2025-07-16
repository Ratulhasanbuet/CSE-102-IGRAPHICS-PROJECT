<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>PACMAN EXTREME - Game Manual</title>
  <style>
    body {
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      background-color: #121212;
      color: #f0f0f0;
      padding: 20px;
      max-width: 960px;
      margin: auto;
    }
    h1, h2 {
      text-align: center;
      color: #ffcb00;
    }
    h2 {
      border-bottom: 2px solid #ffcb00;
      padding-bottom: 5px;
      margin-top: 40px;
    }
    table {
      width: 100%;
      border-collapse: collapse;
      margin: 15px 0;
      background-color: #1e1e1e;
    }
    th, td {
      border: 1px solid #444;
      padding: 10px;
      text-align: left;
    }
    th {
      background-color: #2a2a2a;
      color: #00ffff;
    }
    tr:nth-child(even) {
      background-color: #202020;
    }
    summary {
      cursor: pointer;
      font-weight: bold;
      color: #00ffff;
      margin: 10px 0;
    }
    details {
      background-color: #181818;
      border: 1px solid #333;
      border-radius: 4px;
      margin-bottom: 15px;
      padding: 10px;
    }
    ul {
      padding-left: 20px;
    }
    code {
      background-color: #292929;
      color: #ffcb00;
      padding: 3px 6px;
      border-radius: 3px;
    }
  </style>
</head>
<body>

  <h1>🎮 PACMAN EXTREME</h1>
  <h2>Game Rules & Mechanics</h2>

  <details open>
    <summary>🟡 Objective</summary>
    <ul>
      <li>Eat all dots to complete each maze</li>
      <li>Avoid ghosts — unless they turn vulnerable (blue)</li>
      <li>Collect fruits for bonus score and life</li>
      <li>Advance through four increasingly difficult levels</li>
    </ul>
  </details>

  <details>
    <summary>🧠 Controls</summary>
    <ul>
      <li><code>Arrow Keys</code> → Move Pac-Man</li>
      <li><code>ENTER</code> → Confirm menu selections</li>
      <li><code>ESC</code> → Exit to main menu</li>
      <li><code>Mouse</code> → Navigate menus & hover for UI highlights</li>
    </ul>
  </details>

  <details>
    <summary>💯 Scoring System</summary>
    <table>
      <tr><th>Action</th><th>Points</th></tr>
      <tr><td>Regular Dot</td><td>+10</td></tr>
      <tr><td>Power Pellet</td><td>+40</td></tr>
      <tr><td>Fruit Bonus</td><td>+1000</td></tr>
      <tr><td>Blue Ghosts (Combo)</td><td>+100 → +300 → +900 → +2700</td></tr>
      <tr><td>Maze Completion</td><td>+2000 Bonus</td></tr>
      <tr><td>Fruit Chain</td><td>~5000 (timed)</td></tr>
    </table>
  </details>

  <details>
    <summary>👻 Ghost Behavior</summary>
    <table>
      <tr><th>Mode</th><th>Description</th></tr>
      <tr><td>Scatter</td><td>Retreat to fixed corners</td></tr>
      <tr><td>Chase</td><td>Predict Pac-Man’s movements</td></tr>
      <tr><td>Blast</td><td>High aggression & speed</td></tr>
      <tr><td>Blue</td><td>Vulnerable & flee from Pac-Man</td></tr>
    </table>
    <ul>
      <li><b>Blinky</b> → Direct pursuit</li>
      <li><b>Pinky</b> → Predicts 4 cells ahead</li>
      <li><b>Clyde</b> → Ambushes vertically</li>
      <li><b>Inky</b> → Stalks behind you</li>
      <li><b>Rinky & Donky</b> → Advanced levels; unpredictable logic</li>
    </ul>
  </details>

  <details>
    <summary>🍓 Fruit Mechanics</summary>
    <ul>
      <li>Spawn at fixed time intervals</li>
      <li>Appear at random dot positions</li>
      <li>Grant <code>+1000</code> points</li>
      <li>Fruit 12 or 15 may restore 1 life</li>
      <li>Disappear after ~600 frames</li>
    </ul>
  </details>

  <details>
    <summary>❤️ Lives & Blue Mode</summary>
    <ul>
      <li>Start with 3 lives</li>
      <li>Gain extra life via special fruit</li>
      <li>Lose life on ghost collision</li>
      <li>Game Over at 0 lives → score submission screen</li>
      <li><b>Blue Mode:</b> Ghosts become vulnerable for ~10 seconds</li>
      <li>Speed reduces, animation shifts, combo scoring enabled</li>
    </ul>
  </details>

  <details>
    <summary>🌌 Maze Progression</summary>
    <table>
      <tr><th>Maze</th><th>Size</th><th>Dots</th><th>Ghosts</th><th>Highlights</th></tr>
      <tr><td>Maze 1</td><td>21×21</td><td>226</td><td>4</td><td>Classic style</td></tr>
      <tr><td>Maze 2</td><td>21×21</td><td>236</td><td>4</td><td>Challenging layout</td></tr>
      <tr><td>Maze 3</td><td>19×36</td><td>362</td><td>6</td><td>Includes Rinky & Donky</td></tr>
      <tr><td>Maze 4</td><td>21×40</td><td>454</td><td>6</td><td>Blast mode ghosts</td></tr>
    </table>
  </details>

  <details>
    <summary>🕹️ Menu Functions</summary>
    <table>
      <tr><th>Option</th><th>Function</th></tr>
      <tr><td>Play</td><td>Start gameplay session</td></tr>
      <tr><td>High Score</td><td>Display leaderboard (Top 5)</td></tr>
      <tr><td>Settings</td><td>Toggle sound, background & maze themes</td></tr>
      <tr><td>Difficulty</td><td>Adjust ghost speed & behavior</td></tr>
      <tr><td>Credits / Rules</td><td>View developer info & mechanics</td></tr>
      <tr><td>Quit</td><td>Exit game with animation</td></tr>
    </table>
  </details>

  <details>
    <summary>🧠 Game Logic Features</summary>
    <ul>
      <li>Animated intro, score submission, and exit sequence</li>
      <li>All movement uses smooth pixel alignment logic</li>
      <li>AI ghosts use predictive pathfinding with distance heuristics</li>
      <li>Dynamic sprite rendering per direction & ghost type</li>
      <li>Food states: uneaten (0), eaten (-1), fruit (-2)</li>
      <li>Timers manage score updates, ghost logic, and fruit spawning</li>
      <li>File I/O for top scores (<code>score.txt</code>) and sorting</li>
    </ul>
  </details>

  <details>
    <summary>📊 Difficulty Modes</summary>
    <table>
      <tr><th>Mode</th><th>Ghost Speed</th><th>Pac Speed</th><th>Behavior</th></tr>
      <tr><td>Easy</td><td>2</td><td>3</td><td>Simple chase</td></tr>
      <tr><td>Medium</td><td>3</td><td>3</td><td>Chase
            <tr><td>Hard</td><td>4</td><td>3</td><td>Advanced AI prediction</td></tr>
      <tr><td>Extreme</td><td>4</td><td>4</td><td>Blast mode + ghost chaining</td></tr>
    </table>
  </details>

  <details>
    <summary>🧩 Advanced Features</summary>
    <ul>
      <li>Animated intro sequence (<code>introimage[]</code>)</li>
      <li>Dynamic backgrounds & sprite sets</li>
      <li>Custom maze selector with 8 visual designs</li>
      <li>Fruit spawns managed by frame logic (<code>fruitTimeInterval</code>)</li>
      <li>Sprite animation index flips per movement tick</li>
      <li>Timer-based ghost vulnerability fadeout</li>
      <li>Food status flags:
        <ul>
          <li><code>0</code> → uneaten</li>
          <li><code>-1</code> → eaten</li>
          <li><code>-2</code> → fruit</li>
        </ul>
      </li>
      <li>Ghost behavior shifts based on score milestones:
        <ul>
          <li><code>> 1000</code> → Chase mode</li>
          <li><code>> 6000</code> → Blast mode</li>
        </ul>
      </li>
    </ul>
  </details>

  <details>
    <summary>📁 Save & Score System</summary>
    <ul>
      <li><code>Score.txt</code> stores all submitted scores</li>
      <li>Top 5 scores sorted and displayed via UI</li>
      <li>Scoring uses <code>converter()</code> for text conversion</li>
      <li>File I/O: data is read/written with <code>fprintf()</code> and <code>fscanf()</code></li>
    </ul>
  </details>

  <details>
    <summary>🛠️ Developer Insights</summary>
    <ul>
      <li>Built using <code>iGraphics.h</code> with pixel-based logic</li>
      <li>Ghost AI uses Euclidean distance heuristics + smooth directional handling</li>
      <li>Player controls are responsive to both animation states and cell alignment</li>
      <li>Highly modular codebase with separate draw, movement, and collision functions</li>
      <li>Special thanks and animated outro sequences enhance UX</li>
    </ul>
  </details>

  <footer style="text-align:center; margin-top:40px; font-size:14px; color:#888;">
    Made by Ratul 🎯 | Powered by precision, obsession, and iGraphics ❤️
  </footer>

</body>
</html>
