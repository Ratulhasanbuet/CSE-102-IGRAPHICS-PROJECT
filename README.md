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
