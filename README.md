<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pacman Game - Project Documentation</title>
    <style>
        :root {
            --primary: #FFCC00;
            --secondary: #1A1A2E;
            --accent: #D72323;
            --background: #0F3460;
            --text: #E6E6E6;
            --ghost-pink: #FFB8FF;
            --ghost-blue: #00FFFF;
            --ghost-orange: #FFB851;
            --ghost-red: #FF5555;
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }
        
        body {
            background: linear-gradient(135deg, var(--background), #16213E);
            color: var(--text);
            line-height: 1.6;
            padding: 20px;
            min-height: 100vh;
            background-attachment: fixed;
        }
        
        header {
            text-align: center;
            padding: 40px 20px;
            background: rgba(10, 15, 35, 0.8);
            border-radius: 15px;
            margin-bottom: 30px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.5);
            position: relative;
            overflow: hidden;
            border: 3px solid var(--primary);
        }
        
        header::before {
            content: "";
            position: absolute;
            top: -50%;
            left: -50%;
            width: 200%;
            height: 200%;
            background: radial-gradient(circle, transparent 20%, var(--primary) 20%, transparent 21%);
            background-size: 50px 50px;
            opacity: 0.1;
            z-index: -1;
            animation: pacman-bg 20s linear infinite;
        }
        
        h1 {
            font-size: 3.5rem;
            margin-bottom: 15px;
            color: var(--primary);
            text-shadow: 0 0 15px rgba(255, 204, 0, 0.7);
            letter-spacing: 2px;
        }
        
        .subtitle {
            font-size: 1.5rem;
            color: var(--ghost-blue);
            margin-bottom: 20px;
        }
        
        .main-container {
            max-width: 1200px;
            margin: 0 auto;
            display: grid;
            grid-template-columns: 1fr;
            gap: 25px;
        }
        
        .card {
            background: rgba(26, 26, 46, 0.85);
            border-radius: 15px;
            padding: 30px;
            box-shadow: 0 8px 25px rgba(0, 0, 0, 0.4);
            transition: transform 0.3s ease, box-shadow 0.3s ease;
            border: 2px solid rgba(255, 204, 0, 0.3);
        }
        
        .card:hover {
            transform: translateY(-5px);
            box-shadow: 0 12px 30px rgba(0, 0, 0, 0.5);
            border-color: var(--primary);
        }
        
        .card h2 {
            color: var(--primary);
            font-size: 2rem;
            margin-bottom: 20px;
            padding-bottom: 10px;
            border-bottom: 2px solid var(--accent);
            display: flex;
            align-items: center;
            gap: 10px;
        }
        
        .card h2 i {
            font-size: 1.8rem;
        }
        
        .card h3 {
            color: var(--ghost-blue);
            margin: 20px 0 10px;
            font-size: 1.4rem;
        }
        
        .features-grid {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
            gap: 20px;
            margin-top: 20px;
        }
        
        .feature-item {
            background: rgba(15, 52, 96, 0.6);
            padding: 20px;
            border-radius: 10px;
            border-left: 4px solid var(--primary);
            transition: all 0.3s ease;
        }
        
        .feature-item:hover {
            transform: translateX(5px);
            border-left-width: 8px;
        }
        
        .feature-item h4 {
            color: var(--ghost-orange);
            font-size: 1.2rem;
            margin-bottom: 10px;
            display: flex;
            align-items: center;
            gap: 8px;
        }
        
        .maze-grid {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(280px, 1fr));
            gap: 25px;
            margin-top: 20px;
        }
        
        .maze-card {
            background: rgba(15, 52, 96, 0.7);
            border-radius: 10px;
            padding: 20px;
            text-align: center;
            border: 2px solid transparent;
            transition: all 0.3s ease;
        }
        
        .maze-card:hover {
            border-color: var(--primary);
            box-shadow: 0 0 20px rgba(255, 204, 0, 0.3);
        }
        
        .maze-preview {
            width: 100%;
            height: 150px;
            background: #0A0F1E;
            margin: 15px 0;
            border-radius: 8px;
            position: relative;
            overflow: hidden;
        }
        
        .maze-preview::before {
            content: "";
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-image: 
                linear-gradient(rgba(26, 26, 46, 0.8), rgba(26, 26, 46, 0.8)),
                radial-gradient(circle at 30% 30%, var(--ghost-pink) 3px, transparent 3px),
                radial-gradient(circle at 70% 30%, var(--ghost-red) 3px, transparent 3px),
                radial-gradient(circle at 30% 70%, var(--ghost-blue) 3px, transparent 3px),
                radial-gradient(circle at 70% 70%, var(--ghost-orange) 3px, transparent 3px);
            background-size: 100%, 20px 20px;
            opacity: 0.8;
        }
        
        .ghost-container {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            gap: 25px;
            margin-top: 20px;
        }
        
        .ghost-card {
            width: 150px;
            background: rgba(15, 52, 96, 0.7);
            border-radius: 10px;
            padding: 20px;
            text-align: center;
            transition: transform 0.3s ease;
        }
        
        .ghost-card:hover {
            transform: scale(1.05);
        }
        
        .ghost-icon {
            width: 80px;
            height: 80px;
            border-radius: 50%;
            margin: 0 auto 15px;
            position: relative;
        }
        
        .ghost-icon::after {
            content: "";
            position: absolute;
            bottom: -10px;
            left: 0;
            width: 100%;
            height: 20px;
            background: inherit;
            clip-path: polygon(
                0 0, 20px 0, 25px 10px, 35px 0, 45px 10px, 
                55px 0, 65px 10px, 75px 0, 80px 10px, 
                100% 0, 100% 100%, 0 100%
            );
        }
        
        .blinky { background: var(--ghost-red); }
        .pinky { background: var(--ghost-pink); }
        .inky { background: var(--ghost-blue); }
        .clyde { background: var(--ghost-orange); }
        .rinky { background: #A020F0; }
        .donky { background: #32CD32; }
        
        .controls {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(200px, 1fr));
            gap: 15px;
            margin-top: 20px;
        }
        
        .control-item {
            background: rgba(15, 52, 96, 0.6);
            padding: 15px;
            border-radius: 10px;
            text-align: center;
            border: 1px solid rgba(255, 204, 0, 0.4);
        }
        
        .key {
            display: inline-block;
            background: var(--secondary);
            padding: 8px 15px;
            border-radius: 5px;
            font-weight: bold;
            color: var(--primary);
            margin-top: 8px;
            border: 1px solid var(--primary);
        }
        
        footer {
            text-align: center;
            padding: 30px 0;
            margin-top: 40px;
            border-top: 1px solid rgba(255, 204, 0, 0.3);
        }
        
        .highlight {
            color: var(--primary);
            font-weight: bold;
        }
        
        .code-block {
            background: rgba(10, 15, 35, 0.8);
            padding: 20px;
            border-radius: 10px;
            margin: 20px 0;
            font-family: monospace;
            overflow-x: auto;
            border-left: 4px solid var(--accent);
        }
        
        @keyframes pacman-bg {
            0% { transform: rotate(0deg); }
            100% { transform: rotate(360deg); }
        }
        
        @media (max-width: 768px) {
            .features-grid, .maze-grid, .controls {
                grid-template-columns: 1fr;
            }
            
            h1 {
                font-size: 2.5rem;
            }
        }
    </style>
</head>
<body>
    <div class="main-container">
        <header>
            <h1>PACMAN GAME</h1>
            <p class="subtitle">A Modern C Implementation with Advanced Features</p>
            <p>Classic arcade gameplay with enhanced mechanics, multiple mazes, and intelligent ghost AI</p>
        </header>
        
        <section class="card">
            <h2><i>🎮</i> Game Overview</h2>
            <p>This Pacman implementation features a complete game engine built with C and the iGraphics library. It includes all the classic elements of the original arcade game with modern enhancements including multiple maze designs, difficulty levels, ghost behaviors, and power-up systems.</p>
            
            <div class="code-block">
                // Core game structure<br>
                typedef struct {<br>
                &nbsp;&nbsp;int upInd, downInd, leftInd, rightInd;<br>
                &nbsp;&nbsp;int x, y;<br>
                &nbsp;&nbsp;bool upCount, downCount, leftCount, rightCount;<br>
                &nbsp;&nbsp;bool smoothRight, smoothLeft, smoothUp, smoothDown;<br>
                &nbsp;&nbsp;int right, left, up, down;<br>
                } pacmove;<br><br>
                
                typedef struct {<br>
                &nbsp;&nbsp;int upInd, downInd, leftInd, rightInd;<br>
                &nbsp;&nbsp;int x, y;<br>
                &nbsp;&nbsp;int cellX, cellY;<br>
                &nbsp;&nbsp;bool flagRight, flagLeft, flagUp, flagDown;<br>
                &nbsp;&nbsp;int left, right, up, down;<br>
                &nbsp;&nbsp;int speed;<br>
                &nbsp;&nbsp;bool blueOn; // Vulnerable state<br>
                &nbsp;&nbsp;int dist1, dist2; // Pathfinding metrics<br>
                } ghost;
            </div>
        </section>
        
        <section class="card">
            <h2><i>🌟</i> Key Features</h2>
            <div class="features-grid">
                <div class="feature-item">
                    <h4><i>🧩</i> Multiple Maze Designs</h4>
                    <p>Four unique mazes with different layouts and challenges, each with their own coordinate systems and wall placements.</p>
                </div>
                
                <div class="feature-item">
                    <h4><i>👻</i> Intelligent Ghost AI</h4>
                    <p>Ghosts with unique behaviors: Blinky (aggressive), Pinky (ambusher), Inky (unpredictable), Clyde (random), plus two additional ghosts for larger mazes.</p>
                </div>
                
                <div class="feature-item">
                    <h4><i>🎚️</i> Adjustable Difficulty</h4>
                    <p>Five difficulty levels that affect ghost speed and behavior patterns, changing how they chase Pacman.</p>
                </div>
                
                <div class="feature-item">
                    <h4><i>🍒</i> Power-ups & Fruits</h4>
                    <p>Power pellets that make ghosts vulnerable and 16 different fruits that appear at intervals for bonus points.</p>
                </div>
                
                <div class="feature-item">
                    <h4><i>📊</i> Scoring System</h4>
                    <p>Points for dots, fruits, and eating ghosts. Multipliers for consecutive ghost captures during power mode.</p>
                </div>
                
                <div class="feature-item">
                    <h4><i>💾</i> High Score Tracking</h4>
                    <p>Persistent high score system that saves top players and their achievements.</p>
                </div>
            </div>
        </section>
        
        <section class="card">
            <h2><i>🧱</i> Maze System</h2>
            <div class="maze-grid">
                <div class="maze-card">
                    <h3>Maze 1</h3>
                    <p>21×21 grid</p>
                    <p>Classic layout with 4 power pellets</p>
                    <div class="maze-preview"></div>
                </div>
                
                <div class="maze-card">
                    <h3>Maze 2</h3>
                    <p>21×21 grid</p>
                    <p>Modified classic with strategic choke points</p>
                    <div class="maze-preview"></div>
                </div>
                
                <div class="maze-card">
                    <h3>Maze 3</h3>
                    <p>19×36 grid</p>
                    <p>Wide layout with long corridors</p>
                    <div class="maze-preview"></div>
                </div>
                
                <div class="maze-card">
                    <h3>Maze 4</h3>
                    <p>21×40 grid</p>
                    <p>Largest maze with complex pathways</p>
                    <div class="maze-preview"></div>
                </div>
            </div>
            
            <div class="code-block">
                // Maze coordinate storage<br>
                void corrdinatestore1() {<br>
                &nbsp;&nbsp;int dx = startX12, dy = startY12;<br>
                &nbsp;&nbsp;for (int i = 0; i < 21; i++) {<br>
                &nbsp;&nbsp;&nbsp;&nbsp;for (int j = 0; j < 21; j++) {<br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;map1CoordinateX[i][j] = dx;<br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;map1CoordinateY[i][j] = dy;<br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dx += mazeCellWidth;<br>
                &nbsp;&nbsp;&nbsp;&nbsp;}<br>
                &nbsp;&nbsp;&nbsp;&nbsp;dx = startX12;<br>
                &nbsp;&nbsp;&nbsp;&nbsp;dy -= mazeCellWidth;<br>
                &nbsp;&nbsp;}<br>
                }
            </div>
        </section>
        
        <section class="card">
            <h2><i>👻</i> Ghost System</h2>
            <p>Ghosts implement sophisticated pathfinding algorithms with two main behavior modes:</p>
            
            <div class="ghost-container">
                <div class="ghost-card">
                    <div class="ghost-icon blinky"></div>
                    <h3>Blinky</h3>
                    <p>Aggressive chaser</p>
                </div>
                
                <div class="ghost-card">
                    <div class="ghost-icon pinky"></div>
                    <h3>Pinky</h3>
                    <p>Ambush strategist</p>
                </div>
                
                <div class="ghost-card">
                    <div class="ghost-icon inky"></div>
                    <h3>Inky</h3>
                    <p>Unpredictable follower</p>
                </div>
                
                <div class="ghost-card">
                    <div class="ghost-icon clyde"></div>
                    <h3>Clyde</h3>
                    <p>Random wanderer</p>
                </div>
                
                <div class="ghost-card">
                    <div class="ghost-icon rinky"></div>
                    <h3>Rinky</h3>
                    <p>Added for larger mazes</p>
                </div>
                
                <div class="ghost-card">
                    <div class="ghost-icon donky"></div>
                    <h3>Donky</h3>
                    <p>Added for larger mazes</p>
                </div>
            </div>
            
            <h3>Behavior Modes</h3>
            <ul>
                <li><span class="highlight">Scatter Mode:</span> Ghosts move toward their designated corners</li>
                <li><span class="highlight">Chase Mode:</span> Ghosts use unique strategies to pursue Pacman:
                    <ul>
                        <li>Blinky: Direct path to Pacman</li>
                        <li>Pinky: Targets 4 tiles ahead of Pacman's direction</li>
                        <li>Inky: Uses Pacman's position and Blinky's position to calculate intercept point</li>
                        <li>Clyde: Switches between chasing and scattering based on distance</li>
                    </ul>
                </li>
            </ul>
            
            <div class="code-block">
                // Ghost pathfinding logic<br>
                void directionGenarator(int a, int pookietype) {<br>
                &nbsp;&nbsp;// Calculate distances to Pacman<br>
                &nbsp;&nbsp;int distUp = calcDist(pookie[pookietype].x, ...);<br>
                &nbsp;&nbsp;int distDown = ...<br>
                &nbsp;&nbsp;int distLeft = ...<br>
                &nbsp;&nbsp;int distRight = ...<br>
                &nbsp;&nbsp;int currentDist = ...<br><br>
                
                &nbsp;&nbsp;// Choose direction based on strategy<br>
                &nbsp;&nbsp;if (scatter) { /* Move to corners */ }<br>
                &nbsp;&nbsp;else if (chase) { /* Implement ghost-specific strategies */ }<br>
                }
            </div>
        </section>
        
        <section class="card">
            <h2><i>🎮</i> Game Mechanics</h2>
            
            <h3>Power-up System</h3>
            <p>Special pellets that turn ghosts blue and vulnerable for a limited time:</p>
            <ul>
                <li>Ghosts change appearance to indicate vulnerable state</li>
                <li>Eating a vulnerable ghost awards increasing points (200, 400, 800, 1600)</li>
                <li>Ghosts flash when the effect is about to wear off</li>
            </ul>
            
            <h3>Fruit System</h3>
            <p>16 different fruits appear at specific time intervals:</p>
            <ul>
                <li>Each fruit type has different point values</li>
                <li>Appear in the center of the maze</li>
                <li>Disappear after a short time if not collected</li>
            </ul>
            
            <h3>Scoring</h3>
            <ul>
                <li>Regular dots: 10 points</li>
                <li>Power pellets: 50 points</li>
                <li>Fruits: 100-1600 points (depending on type)</li>
                <li>Ghosts: 200, 400, 800, 1600 points (increasing with each consecutive capture)</li>
            </ul>
            
            <div class="code-block">
                // Power pellet activation<br>
                void bluetimecheck() {<br>
                &nbsp;&nbsp;if (blueGhost > 0) {<br>
                &nbsp;&nbsp;&nbsp;&nbsp;blueGhost--;<br>
                &nbsp;&nbsp;&nbsp;&nbsp;if (blueGhost <= 100) { // Flash warning<br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (int i = 0; i < ghostCount; i++) {<br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pookie[i].blueOn = (blueGhost / 10) % 2;<br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
                &nbsp;&nbsp;&nbsp;&nbsp;}<br>
                &nbsp;&nbsp;}<br>
                }
            </div>
        </section>
        
        <section class="card">
            <h2><i>🕹️</i> Controls</h2>
            <div class="controls">
                <div class="control-item">
                    <h3>Movement</h3>
                    <p>Arrow Keys</p>
                    <div class="key">↑</div>
                    <div class="key">↓</div>
                    <div class="key">←</div>
                    <div class="key">→</div>
                </div>
                
                <div class="control-item">
                    <h3>Pause/Resume</h3>
                    <p>P Key</p>
                    <div class="key">P</div>
                </div>
                
                <div class="control-item">
                    <h3>Menu Navigation</h3>
                    <p>Mouse</p>
                    <div class="key">Click</div>
                </div>
                
                <div class="control-item">
                    <h3>Name Entry</h3>
                    <p>Keyboard</p>
                    <div class="key">A-Z</div>
                </div>
            </div>
        </section>
        
        <section class="card">
            <h2><i>💻</i> Technical Implementation</h2>
            
            <h3>Core Systems</h3>
            <ul>
                <li>Custom animation system for Pacman and ghosts</li>
                <li>Collision detection with maze walls and collectibles</li>
                <li>State management for game modes and menus</li>
                <li>Pathfinding algorithms for ghost movement</li>
            </ul>
            
            <h3>Menu System</h3>
            <p>Comprehensive UI with multiple screens:</p>
            <ul>
                <li>Main menu with animations</li>
                <li>Difficulty selection</li>
                <li>Maze selection</li>
                <li>High score display</li>
                <li>Settings (sound, background)</li>
                <li>Game rules</li>
                <li>Credits screen</li>
            </ul>
            
            <div class="code-block">
                // Game state management<br>
                bool soundOn = true;<br>
                bool startintro = true;<br>
                bool mainmenu;<br>
                bool difficulty;<br>
                bool playgameintro;<br>
                bool highscore;<br>
                bool settings;<br>
                bool credits;<br>
                bool rules;<br>
                bool quit;<br>
                bool mazeselector;<br>
                bool playingstart;<br>
                bool levelselect;<br>
                bool pause;<br>
                bool backgroundselector;<br>
                bool deadscene;<br>
                bool congrats;
            </div>
        </section>
        
        <footer>
            <p>PACMAN GAME PROJECT | C & iGraphics Implementation</p>
            <p>Complete with all original features plus modern enhancements</p>
        </footer>
    </div>
</body>
</html>