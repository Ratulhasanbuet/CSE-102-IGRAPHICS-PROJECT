<!-- index.html -->
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Pac-Man Game Guide</title>
  <link rel="stylesheet" href="styles.css">
</head>
<body>
  <header>
    <h1>Pac-Man Game Guide</h1>
    <p>Your one-stop reference for gameplay, controls, features & code.</p>
  </header>

  <nav>
    <ul>
      <li><a href="#overview">Overview</a></li>
      <li><a href="#how-to-play">How to Play</a></li>
      <li><a href="#controls">Controls</a></li>
      <li><a href="#elements">Game Elements</a></li>
      <li><a href="#mazes">Mazes</a></li>
      <li><a href="#settings">Settings & Menus</a></li>
      <li><a href="#structure">Code Structure</a></li>
      <li><a href="#mindmap">Mind Map</a></li>
      <li><a href="#tips">Tips & Tricks</a></li>
    </ul>
  </nav>

  <section id="overview">
    <h2>1. Overview</h2>
    <p>Pac-Man is a classic maze–chase arcade game. Control Pac-Man, gobble pellets, dodge ghosts, eat power-pellets to chase them back, and collect fruits for bonus points or extra lives.</p>
  </section>

  <section id="how-to-play">
    <h2>2. How to Play</h2>
    <ul>
      <li>Use the arrow keys to navigate the maze.</li>
      <li>Eat all small pellets to clear a level.</li>
      <li>Power-pellets turn ghosts blue—eat them before time runs out.</li>
      <li>Catch bonus fruits for 1,000 points or extra lives.</li>
      <li>You have 3 lives—losing them all ends the game.</li>
      <li>High scores get saved automatically.</li>
    </ul>
  </section>

  <section id="controls">
    <h2>3. Controls</h2>
    <table>
      <tr><th>Key</th><th>Action</th></tr>
      <tr><td>←</td><td>Move Left</td></tr>
      <tr><td>→</td><td>Move Right</td></tr>
      <tr><td>↑</td><td>Move Up</td></tr>
      <tr><td>↓</td><td>Move Down</td></tr>
      <tr><td>P</td><td>Pause/Resume</td></tr>
      <tr><td>Q/ESC</td><td>Quit to menu/Exit game</td></tr>
    </table>
  </section>

  <section id="elements">
    <h2>4. Game Elements</h2>
    <details>
      <summary>Pac-Man</summary>
      <p>A yellow circle you control. Animates as it moves.</p>
    </details>
    <details>
      <summary>Pellets & Power-Pellets</summary>
      <ul>
        <li>Regular: 10 points</li>
        <li>Power: 50 points + ghosts blue</li>
      </ul>
    </details>
    <details>
      <summary>Fruit (Bonus)</summary>
      <p>Appears randomly. Grants 1,000 points or extra life.</p>
    </details>
    <details>
      <summary>Ghosts</summary>
      <ul>
        <li><strong>Blinky</strong> (Red): Direct chase</li>
        <li><strong>Pinky</strong> (Pink): Ambush ahead</li>
        <li><strong>Inky</strong> (Cyan): Unpredictable</li>
        <li><strong>Clyde</strong> (Orange): Alternates chase/scatter</li>
        <li><strong>Donky & Rinky</strong>: Extra ghosts on bigger mazes</li>
      </ul>
      <p>Modes: Scatter, Chase, Frightened (blue), Elroy (fast mode at high score).</p>
    </details>
  </section>

  <section id="mazes">
    <h2>5. Maze Variants</h2>
    <table>
      <tr>
        <th>Level</th><th>Size</th><th>Pellets</th><th>Power-Pellets</th><th>Ghosts</th>
      </tr>
      <tr><td>1</td><td>21×21</td><td>226</td><td>4</td><td>4</td></tr>
      <tr><td>2</td><td>21×21</td><td>236</td><td>4</td><td>4</td></tr>
      <tr><td>3</td><td>19×36</td><td>362</td><td>4</td><td>6</td></tr>
      <tr><td>4</td><td>21×40</td><td>454</td><td>7</td><td>6</td></tr>
    </table>
  </section>

  <section id="settings">
    <h2>6. Settings & Menus</h2>
    <ul>
      <li>Main Menu: Start, High Score, Settings, Credits, Rules, Quit</li>
      <li>Difficulty: Adjusts speeds & AI behavior</li>
      <li>Sound: On/Off toggle (SDL2 mixer)</li>
      <li>Background: 5 themes</li>
      <li>High Score: Top 5 saved and displayed</li>
    </ul>
  </section>

  <section id="structure">
    <h2>7. Code Structure</h2>
    <ul>
      <li><code>corrdinatestoreX()</code>: Map grid to coordinates</li>
      <li><code>drawMazeX()</code> & <code>drawFoodAndPowerPellet()</code></li>
      <li>Movement: <code>pacmanmovement()</code>, <code>pookiemovement()</code></li>
      <li>Collision: <code>collisioncheck()</code></li>
      <li>Timers: pellet respawn, ghost-mode timers</li>
      <li>High Score: <code>DataAnalysis()</code> reads/writes text file</li>
    </ul>
  </section>

  <section id="mindmap">
    <h2>8. Mind Map</h2>
    <article class="mindmap">
      <ul>
        <li>Pac-Man Game
          <ul>
            <li>Gameplay
              <ul>
                <li>Controls</li>
                <li>Scoring</li>
                <li>Objectives</li>
              </ul>
            </li>
            <li>Characters
              <ul>
                <li>Pac-Man</li>
                <li>Ghosts (4–6)</li>
              </ul>
            </li>
            <li>Mazes (4 Variants)</li>
            <li>Settings (Sound, Difficulty)</li>
          </ul>
        </li>
      </ul>
    </article>
  </section>

  <section id="tips">
    <h2>9. Tips & Tricks</h2>
    <ol>
      <li>Corner-hug in scatter mode.</li>
      <li>Don’t reverse in tight spots.</li>
      <li>Only chase ghosts after eating power-pellet.</li>
      <li>Use extra lives for high-score runs.</li>
    </ol>
  </section>

  <footer>
    <p>© 2025 Your Name | Built with iGraphics</p>
  </footer>
</body>
</html>
