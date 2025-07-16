<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Pac-Man — iGraphics Project</title>
  <style>
    body {
      background-color: #0d0d0d;
      color: #f5f5f5;
      font-family: 'Segoe UI', sans-serif;
      margin: 0;
      padding: 20px;
    }
    h1, h2 {
      color: #ffe100;
      border-bottom: 2px solid #333;
      padding-bottom: 5px;
    }
    .image-grid {
      display: flex;
      flex-wrap: wrap;
      gap: 10px;
      margin-bottom: 20px;
    }
    .image-grid img {
      width: 180px;
      border: 2px solid #444;
    }
    .code-block {
      background: #1a1a1a;
      color: #ccc;
      padding: 15px;
      font-family: monospace;
      border-left: 5px solid #ffe100;
      margin: 20px 0;
      overflow-x: auto;
    }
    table {
      border-collapse: collapse;
      margin-top: 10px;
      width: 100%;
    }
    table td, table th {
      border: 1px solid #444;
      padding: 8px;
    }
    table th {
      background-color: #222;
      color: #ffe100;
    }
  </style>
</head>
<body>

  <h1>🟡 Pac-Man (iGraphics Edition)</h1>
  <p>A full-featured Pac-Man game coded in C using the <code>iGraphics.h</code> library. Includes customizable mazes, fruit spawning, dynamic ghost AI (including Donky & Rinky), scoring mechanics, and menu transitions.</p>
  <section style="background-color: #1b1b1b; color: #ffe100; padding: 20px; font-family: 'Segoe UI', sans-serif;">
  <h2 style="border-bottom: 2px solid #ffe100;">✍️ Author Credits</h2>
  <p><strong>Designed & Programmed by:</strong><br>
     Md Ratul Hasan, CSE'24<br>
     Hasibul Islam, CSE'24</p>
  <p><strong>Instructed by:</strong><br>
     Abdur Rafi</p>
</section>


  <h2>🎮 Maze Previews</h2>
  <div class="image-grid">
    <img src="mazeDesignImage/pixel.png" alt="Pixel Maze">
    <img src="mazeDesignImage/nebula.png" alt="Nebula Maze">
    <img src="mazeDesignImage/spectral.png" alt="Spectral Maze">
    <img src="mazeDesignImage/psi.png" alt="Psi Maze">
    <img src="mazeDesignImage/crack.png" alt="Crack Maze">
    <img src="mazeDesignImage/echo.png" alt="Echo Maze">
    <img src="mazeDesignImage/phantom.png" alt="Phantom Maze">
    <img src="mazeDesignImage/spiral.png" alt="Spiral Maze">
  </div>

  <h2>🧱 Maze Logic Example (Maze 1)</h2>
  <div class="code-block">
<pre>
int maze1[21][21] = {
  {1, 1, 1, 1, ..., 1},
  {1, 0, 0, 0, ..., 1},
  ...
};
</pre>
  </div>

  <h2>👾 Ghost AI Behavior</h2>
  <table>
    <tr>
      <th>Ghost</th>
      <th>Image</th>
      <th>Behavior</th>
    </tr>
    <tr>
      <td>Inky</td>
      <td><img src="inky/inky (1).png" width="40"/></td>
      <td>Chases behind Pac-Man</td>
    </tr>
    <tr>
      <td>Blinky</td>
      <td><img src="blinky/blinky (1).png" width="40"/></td>
      <td>Direct pursuit</td>
    </tr>
    <tr>
      <td>Pinky</td>
      <td><img src="pinky/pinky (1).png" width="40"/></td>
      <td>Predictive chase</td>
    </tr>
    <tr>
      <td>Clyde</td>
      <td><img src="clyde/clyde (1).png" width="40"/></td>
      <td>Ambush from above</td>
    </tr>
    <tr>
      <td>Donky</td>
      <td><img src="donky/donky1.png" width="40"/></td>
      <td>Wall-hugging, dynamic AI</td>
    </tr>
    <tr>
      <td>Rinky</td>
      <td><img src="rinky/rinky1.png" width="40"/></td>
      <td>Predictive pathfinding</td>
    </tr>
  </table>

  <h2>📦 Game Features</h2>
  <ul>
    <li>🍒 Fruit with bonuses — <code>fruit/fruit (1).png</code></li>
    <li>🌀 Dynamic maze rendering via <code>drawMaze1/2/3/4()</code></li>
    <li>⏱ Power pellets toggle <code>blueGhost</code> mode</li>
    <li>📈 Scoring system using <code>score.txt</code> and highscore tracking</li>
    <li>📃 Menu with credits, rules, difficulty selector</li>
  </ul>

  <h2>⚙️ How to Run</h2>
  <ol>
    <li>Ensure <code>iGraphics.h</code> and OpenGL libraries are linked in your compiler.</li>
    <li>Compile the project (`pacman.txt`) and run the main executable.</li>
    <li>Use arrow keys for movement and mouse for menu interaction.</li>
  </ol>

  <h2>🎉 Credit</h2>
  <p><strong>Designed and Developed by Ratul</strong> — with intricate gameplay refinement, creative ghost logic, and sprite mapping brilliance.</p>

</body>
</html>
