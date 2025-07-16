<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>PACMAN EXTREME - Rules</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #0d0d0d;
      color: #f2f2f2;
      line-height: 1.6;
      padding: 40px;
      max-width: 900px;
      margin: auto;
    }
    h1, h2 {
      color: #ffdd00;
      text-align: center;
    }
    h2 {
      border-bottom: 2px solid #ffdd00;
      padding-bottom: 5px;
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
    .section {
      margin-top: 40px;
    }
  </style>
</head>
<body>

  <h1>PACMAN EXTREME</h1>
  <h2>🎮 GAME RULES & GUIDE</h2>

  <div class="section">
    <h3>🎯 Objective</h3>
    <ul>
      <li>Eat all dots to clear the maze</li>
      <li>Avoid ghosts unless they’re vulnerable (blue)</li>
      <li>Collect fruits for score boosts</li>
      <li>Advance through increasingly difficult mazes</li>
    </ul>
  </div>

  <div class="section">
    <h3>🧠 Controls</h3>
    <ul>
      <li><code>Arrow Keys</code> – Move Pac-Man</li>
      <li><code>ESC</code> – Quit to Menu</li>
      <li><code>ENTER</code> – Confirm selections</li>
    </ul>
  </div>

  <div class="section">
    <h3>💯 Scoring System</h3>
    <table>
      <tr><th>Action</th><th>Points</th></tr>
      <tr><td>Eat Regular Dot</td><td>+10</td></tr>
      <tr><td>Eat Power Pellet</td><td>+40</td></tr>
      <tr><td>Eat Fruit</td><td>+1000</td></tr>
      <tr><td>Eat Blue Ghosts</td><td>+100 → +300 → +900 → +2700</td></tr>
      <tr><td>Complete Maze</td><td>+2000 Bonus</td></tr>
    </table>
  </div>

  <div class="section">
    <h3>👻 Ghost Behavior</h3>
    <table>
      <tr><th>Mode</th><th>Description</th></tr>
      <tr><td>Scatter</td><td>Ghosts retreat to preset corners</td></tr>
      <tr><td>Chase</td><td>Predictive movement targeting Pac-Man</td></tr>
      <tr><td>Blast</td><td>Maximum speed and aggression</td></tr>
      <tr><td>Blue</td><td>Ghosts slow down and become vulnerable</td></tr>
    </table>
    <ul>
      <li><strong>Blinky</strong> – Direct hunter</li>
      <li><strong>Pinky</strong> – Predictive logic</li>
      <li><strong>Clyde</strong> – Vertical ambusher</li>
      <li><strong>Inky</strong> – Trails behind</li>
      <li><strong>Rinky & Donky</strong> – Appear in Maze 3 & 4, unpredictable behavior</li>
    </ul>
  </div>

  <div class="section">
    <h3>🍓 Fruit Mechanics</h3>
    <ul>
      <li>Spawn at intervals, random positions</li>
      <li>Provide <code>+1000</code> points</li>
      <li>May grant extra life on rare occasion</li>
      <li>Vanishes if not collected within time limit</li>
    </ul>
  </div>

  <div class="section">
    <h3>❤️ Lives</h3>
    <ul>
      <li>Start with 3 lives</li>
      <li>Extra life from special fruits</li>
      <li>Lose one life on contact with ghosts (unless blue)</li>
      <li>Game over when lives reach zero</li>
    </ul>
  </div>

  <div class="section">
    <h3>🌌 Maze Progression</h3>
    <table>
      <tr>
        <th>Maze</th><th>Size</th><th>Dots</th><th>Ghosts</th><th>Notes</th>
      </tr>
      <tr><td>Maze 1</td><td>21×21</td><td>226</td><td>4</td><td>Beginner Level</td></tr>
      <tr><td>Maze 2</td><td>21×21</td><td>236</td><td>4</td><td>Intermediate</td></tr>
      <tr><td>Maze 3</td><td>19×36</td><td>362</td><td>6</td><td>Rinky & Donky appear</td></tr>
      <tr><td>Maze 4</td><td>21×40</td><td>454</td><td>6</td><td>High difficulty</td></tr>
    </table>
  </div>

  <div class="section">
    <h3>🕹️ Menu Options</h3>
    <table>
      <tr><th>Option</th><th>Function</th></tr>
      <tr><td>Play</td><td>Starts the game</td></tr>
      <tr><td>High Score</td><td>Displays top 5 entries</td></tr>
      <tr><td>Settings</td><td>Background, sound toggle, maze design</td></tr>
      <tr><td>Difficulty</td><td>Adjust game speed and AI logic</td></tr>
      <tr><td>Credits & Rules</td><td>Info and game mechanics</td></tr>
      <tr><td>Quit</td><td>Exits with farewell animation</td></tr>
    </table>
  </div>

  <div class="section">
    <h3>🧠 Pro Tips</h3>
    <ul>
      <li>Chain ghost eats in blue mode for insane scores</li>
      <li>Grab fruit quickly before it vanishes</li>
      <li>Use pellet timing for ghost crowd control</li>
      <li>Track ghost paths and predict corners</li>
    </ul>
  </div>

</body>
</html>
