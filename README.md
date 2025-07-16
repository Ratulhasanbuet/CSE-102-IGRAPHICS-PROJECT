<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <title>Pac-Man — iGraphics Edition</title>
  <link rel="stylesheet" href="style.css" />
</head>
<body>

  <h1>🟡 Pac-Man (iGraphics Edition)</h1>
  <p>A classic Pac-Man remake using C and <code>iGraphics.h</code>. Features multiple maze themes, ghost AI modes, scoring, fruits, and dynamic UI transitions.</p>

  <section id="author">
    <h2>✍️ Author Credits</h2>
    <p><strong>Designed & Programmed by:</strong> Md Ratul Hasan, CSE'24 & Hasibul Islam, CSE'24</p>
    <p><strong>Instructed by:</strong> Abdur Rafi</p>
  </section>

  <section id="menu">
    <h2>📋 Main Menu Overview</h2>
    <img src="menu image/PACMAN.png" alt="Main Menu Screenshot" />
    <ul>
      <li><strong>Play Game</strong> — Start and choose levels</li>
      <li><strong>High Score</strong> — View player stats from <code>highScore.txt</code></li>
      <li><strong>Settings</strong> — Sound toggle and maze selection</li>
      <li><strong>Difficulty</strong> — Set ghost speed and AI behavior</li>
      <li><strong>Credits</strong> — Developer and mentor names</li>
      <li><strong>Rules</strong> — Gameplay mechanics overview</li>
      <li><strong>Quit</strong> — Trigger animated game exit</li>
      <li><strong>Special Thanks</strong> — Acknowledgments page</li>
    </ul>
  </section>

  <section id="maze-gallery">
    <h2>🎮 Maze Gallery</h2>
    <div class="maze-grid">
      <img src="mazeDesignImage/pixel.png" alt="Pixel Maze" />
      <img src="mazeDesignImage/nebula.png" alt="Nebula Maze" />
      <img src="mazeDesignImage/spectral.png" alt="Spectral Maze" />
      <img src="mazeDesignImage/psi.png" alt="Psi Maze" />
      <img src="mazeDesignImage/crack.png" alt="Crack Maze" />
      <img src="mazeDesignImage/echo.png" alt="Echo Maze" />
      <img src="mazeDesignImage/phantom.png" alt="Phantom Maze" />
      <img src="mazeDesignImage/spiral.png" alt="Spiral Maze" />
    </div>
  </section>

  <section id="maze-logic">
    <h2>🧱 Maze Logic Snippet</h2>
    <pre><code>int maze1[21][21] = {
  {1, 1, 1, 1, ..., 1},
  {1, 0, 0, 0, ..., 1},
  ...
};</code></pre>
  </section>

  <section id="ghost-ai">
    <h2>👾 Ghost AI</h2>
    <table>
      <thead>
        <tr><th>Ghost</th><th>Preview</th><th>Behavior</th></tr>
      </thead>
      <tbody>
        <tr><td>Inky</td><td><img src="inky/inky (1).png" width="40" /></td><td>Back-track chase</td></tr>
        <tr><td>Blinky</td><td><img src="blinky/blinky (1).png" width="40" /></td><td>Direct pursuit</td></tr>
        <tr><td>Pinky</td><td><img src="pinky/pinky (1).png" width="40" /></td><td>Predictive chase</td></tr>
        <tr><td>Clyde</td><td><img src="clyde/clyde (1).png" width="40" /></td><td>Ambush from side</td></tr>
        <tr><td>Donky</td><td><img src="donky/donky1.png" width="40" /></td><td>Wall-hugging AI</td></tr>
        <tr><td>Rinky</td><td><img src="rinky/rinky1.png" width="40" /></td><td>Smart predictive AI</td></tr>
      </tbody>
    </table>
  </section>

  <section id="features">
    <h2>📦 Game Features</h2>
    <ul>
      <li>Fruit collection bonus (e.g., <code>fruit/fruit (1).png</code>)</li>
      <li>Dynamic maze rendering (<code>drawMazeX()</code> calls)</li>
      <li>Power pellet system with <code>blueGhost</code> mode</li>
      <li>Score tracking via <code>score.txt</code> and high score logic</li>
      <li>Customizable UI for rules, credits, and difficulty</li>
    </ul>
  </section>
  <h2>🧩 Level Breakdown</h2>
<table>
  <thead>
    <tr>
      <th>Level</th>
      <th>Maze Size</th>
      <th>Total Food Pellets</th>
      <th>Power Pellet Indices</th>
      <th>Maze Type</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Level 1</td>
      <td>21 × 21</td>
      <td>226 pellets</td>
      <td>0, 18, 104, 149</td>
      <td>Classic boxy corridors</td>
    </tr>
    <tr>
      <td>Level 2</td>
      <td>21 × 21</td>
      <td>236 pellets</td>
      <td>0, 18, 156, 165</td>
      <td>Symmetrical lattice structure</td>
    </tr>
    <tr>
      <td>Level 3</td>
      <td>19 × 36</td>
      <td>362 pellets</td>
      <td>84, 100, 200, 292</td>
      <td>Long horizontal maze with corridor dynamics</td>
    </tr>
    <tr>
      <td>Level 4</td>
      <td>21 × 40</td>
      <td>454 pellets</td>
      <td>15, 50, 87, 135, 172, 244, 327</td>
      <td>Spiral paths and mixed turns</td>
    </tr>
  </tbody>
</table>
<h2>🍒 Food & Scoring System</h2>

<p>In Pac-Man, food items are central to gameplay — they increase score, trigger ghost vulnerability, and in special cases, grant extra lives. Here's how they work:</p>

<h3>🍽️ Food Types</h3>
<ul>
  <li><strong>Small Pellets</strong> — Basic dots scattered throughout the maze. Each pellet adds <code>+10 points</code>.</li>
  <li><strong>Power Pellets</strong> — Larger glowing dots placed at key corners. Eating one triggers <code>blueGhost</code> mode and adds <code>+50 points</code>.</li>
  <li><strong>Bonus Fruits</strong> — Appear occasionally in the maze center. Each fruit has a unique score value and may trigger special effects.</li>
  <li><strong>Golden Apple</strong> — Grants <span style="color:gold;"><strong>+1 Extra Life</strong></span> when collected. Rare and appears only in Level 4.</li>
</ul>

<h3>📈 Scoring Breakdown</h3>
<ul>
  <li>Small Pellet: <code>+10</code></li>
  <li>Power Pellet: <code>+50</code></li>
  <li>Ghost (Blue Mode): <code>+200</code> per ghost eaten</li>
  <li>Fruit Bonus:
    <ul>
      <li>Cherry: <code>+100</code></li>
      <li>Strawberry: <code>+300</code></li>
      <li>Orange: <code>+500</code></li>
      <li>Apple: <code>+700</code></li>
      <li>Melon: <code>+1000</code></li>
      <li>Galaxian: <code>+2000</code></li>
      <li>Bell: <code>+3000</code></li>
      <li>Key: <code>+5000</code></li>
    </ul>
  </li>
</ul>

<h3>🖼️ Food Gallery</h3>
<div style="display: flex; flex-wrap: wrap; gap: 10px;">
  <img src="fruit/fruit (1).png" alt="Cherry" width="100" />
  <img src="fruit/fruit (2).png" alt="Strawberry" width="100" />
  <img src="fruit/fruit (3).png" alt="Orange" width="100" />
  <img src="fruit/fruit (4).png" alt="Apple" width="100" />
  <img src="fruit/fruit (5).png" alt="Melon" width="100" />
  <img src="fruit/fruit (6).png" alt="Galaxian" width="100" />
  <img src="fruit/fruit (7).png" alt="Bell" width="100" />
  <img src="fruit/fruit (8).png" alt="Key" width="100" />
  <img src="fruit/fruit (9).png" alt="Golden Apple" width="100" />
</div>

<h3>❤️ Extra Life Mechanic</h3>
<p>Collecting the <strong>Golden Apple</strong> (Level 4 only) instantly adds <strong>+1 life</strong> to the player. Lives are tracked visually using:</p>
<img src="life/love (1).png" alt="Life Icon" width="40" />

<p>Lives are capped at 3 unless modified in settings. Losing all lives triggers the game over screen.</p>



  <section id="instructions">
    <h2>⚙️ How to Run</h2>
    <ol>
      <li>Ensure <code>iGraphics.h</code> and GLUT are linked in your compiler</li>
      <li>Compile <code>pacman.txt</code></li>
      <li>Use arrow keys and mouse for gameplay</li>
    </ol>
  </section>

  <section id="footer">
    <h2>🎉 Summary</h2>
    <p><strong>Created by Ratul & Hasibul</strong> — a full arcade journey powered by precision C graphics and creativity. Enjoy strategic gameplay, responsive controls, and unpredictable ghost AI!</p>
  </section>

</body>
</html>
