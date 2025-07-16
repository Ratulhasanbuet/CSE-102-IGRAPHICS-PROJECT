<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pacman Game - CSE-102 iGraphics Project Documentation</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            line-height: 1.6;
            color: #333;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
        }
        
        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
        }
        
        header {
            background: rgba(255, 255, 255, 0.1);
            backdrop-filter: blur(10px);
            border-radius: 15px;
            padding: 30px;
            text-align: center;
            margin-bottom: 30px;
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.1);
        }
        
        h1 {
            color: #FFD700;
            font-size: 3em;
            margin-bottom: 10px;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.3);
        }
        
        .subtitle {
            color: #fff;
            font-size: 1.2em;
            opacity: 0.9;
        }
        
        .nav-menu {
            background: rgba(255, 255, 255, 0.1);
            backdrop-filter: blur(10px);
            border-radius: 15px;
            padding: 20px;
            margin-bottom: 30px;
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.1);
        }
        
        .nav-menu ul {
            list-style: none;
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            gap: 20px;
        }
        
        .nav-menu a {
            color: #fff;
            text-decoration: none;
            padding: 10px 20px;
            border-radius: 25px;
            background: rgba(255, 255, 255, 0.2);
            transition: all 0.3s ease;
            font-weight: 500;
        }
        
        .nav-menu a:hover {
            background: rgba(255, 255, 255, 0.3);
            transform: translateY(-2px);
        }
        
        .section {
            background: rgba(255, 255, 255, 0.95);
            border-radius: 15px;
            padding: 30px;
            margin-bottom: 30px;
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.1);
        }
        
        h2 {
            color: #333;
            font-size: 2.2em;
            margin-bottom: 20px;
            border-bottom: 3px solid #FFD700;
            padding-bottom: 10px;
        }
        
        h3 {
            color: #555;
            font-size: 1.5em;
            margin: 20px 0 10px 0;
            padding-left: 10px;
            border-left: 4px solid #667eea;
        }
        
        .feature-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 20px;
            margin: 20px 0;
        }
        
        .feature-card {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
            transition: transform 0.3s ease;
        }
        
        .feature-card:hover {
            transform: translateY(-5px);
        }
        
        .feature-card h4 {
            font-size: 1.3em;
            margin-bottom: 10px;
            color: #FFD700;
        }
        
        .tech-stack {
            display: flex;
            flex-wrap: wrap;
            gap: 10px;
            margin: 20px 0;
        }
        
        .tech-badge {
            background: #FFD700;
            color: #333;
            padding: 8px 16px;
            border-radius: 20px;
            font-weight: bold;
            font-size: 0.9em;
        }
        
        .code-block {
            background: #2d3748;
            color: #e2e8f0;
            padding: 20px;
            border-radius: 10px;
            margin: 15px 0;
            font-family: 'Courier New', monospace;
            overflow-x: auto;
        }
        
        .controls-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
            gap: 15px;
            margin: 20px 0;
        }
        
        .control-item {
            background: #f8f9fa;
            padding: 15px;
            border-radius: 8px;
            border-left: 4px solid #667eea;
            text-align: center;
        }
        
        .control-key {
            background: #333;
            color: #fff;
            padding: 5px 10px;
            border-radius: 5px;
            font-family: monospace;
            font-weight: bold;
        }
        
        .screenshot-placeholder {
            background: linear-gradient(45deg, #f0f0f0, #e0e0e0);
            border: 2px dashed #ccc;
            border-radius: 10px;
            padding: 40px;
            text-align: center;
            color: #666;
            margin: 20px 0;
            font-style: italic;
        }
        
        .author-info {
            background: linear-gradient(135deg, #FFD700, #FFA500);
            color: #333;
            padding: 20px;
            border-radius: 10px;
            text-align: center;
            margin-top: 30px;
        }
        
        .author-info h3 {
            border: none;
            padding: 0;
            margin-bottom: 10px;
        }
        
        .stats-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
            gap: 15px;
            margin: 20px 0;
        }
        
        .stat-card {
            background: #f8f9fa;
            padding: 20px;
            border-radius: 10px;
            text-align: center;
            border: 2px solid #e9ecef;
        }
        
        .stat-number {
            font-size: 2em;
            font-weight: bold;
            color: #667eea;
        }
        
        .stat-label {
            color: #666;
            font-size: 0.9em;
        }
        
        @media (max-width: 768px) {
            .nav-menu ul {
                flex-direction: column;
                align-items: center;
            }
            
            h1 {
                font-size: 2em;
            }
            
            .container {
                padding: 10px;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header>
            <h1>🎮 PACMAN GAME</h1>
            <p class="subtitle">CSE-102 iGraphics Project Documentation</p>
            <p class="subtitle">Built with C Programming Language & iGraphics Library</p>
        </header>
        
        <nav class="nav-menu">
            <ul>
                <li><a href="#overview">Overview</a></li>
                <li><a href="#features">Features</a></li>
                <li><a href="#gameplay">Gameplay</a></li>
                <li><a href="#controls">Controls</a></li>
                <li><a href="#technical">Technical Details</a></li>
                <li><a href="#installation">Installation</a></li>
                <li><a href="#source">Source Code</a></li>
            </ul>
        </nav>
        
        <section id="overview" class="section">
            <h2>🎯 Project Overview</h2>
            <p>This is a complete implementation of the classic Pacman arcade game developed as a term project for CSE-102 (Structured Programming Language) course at BUET. The game is built using C programming language with the iGraphics library for graphics rendering and user interaction.</p>
            
            <div class="stats-grid">
                <div class="stat-card">
                    <div class="stat-number">1000+</div>
                    <div class="stat-label">Lines of Code</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">C</div>
                    <div class="stat-label">Programming Language</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">iGraphics</div>
                    <div class="stat-label">Graphics Library</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">4</div>
                    <div class="stat-label">Ghost AI Types</div>
                </div>
            </div>
            
            <h3>🎮 Game Description</h3>
            <p>Experience the classic arcade nostalgia with this faithful recreation of Pacman. Navigate through maze-like levels, collect dots while avoiding intelligent ghosts, and use power pellets to turn the tables on your pursuers. The game features multiple difficulty levels, scoring system, and authentic arcade-style gameplay mechanics.</p>
            
            <div class="tech-stack">
                <span class="tech-badge">C Programming</span>
                <span class="tech-badge">iGraphics Library</span>
                <span class="tech-badge">OpenGL</span>
                <span class="tech-badge">Game AI</span>
                <span class="tech-badge">2D Graphics</span>
                <span class="tech-badge">Sound Effects</span>
            </div>
        </section>
        
        <section id="features" class="section">
            <h2>✨ Key Features</h2>
            
            <div class="feature-grid">
                <div class="feature-card">
                    <h4>🧠 Intelligent Ghost AI</h4>
                    <p>Four different ghost types with unique behaviors - Blinky (aggressive), Pinky (ambush), Inky (unpredictable), and Clyde (patrol). Each ghost has distinct movement patterns and chase algorithms.</p>
                </div>
                
                <div class="feature-card">
                    <h4>🎯 Multiple Game Modes</h4>
                    <p>Classic arcade mode with progressive difficulty, time-based challenges, and survival mode. Each mode offers unique gameplay mechanics and scoring systems.</p>
                </div>
                
                <div class="feature-card">
                    <h4>🏆 Scoring System</h4>
                    <p>Comprehensive scoring with points for dots (10), power pellets (50), ghosts (200-1600), and bonus fruits (100-5000). High score tracking and leaderboard functionality.</p>
                </div>
                
                <div class="feature-card">
                    <h4>🎨 Visual Effects</h4>
                    <p>Smooth animations, particle effects, screen transitions, and authentic arcade-style graphics with customizable themes and color schemes.</p>
                </div>
                
                <div class="feature-card">
                    <h4>🔊 Audio System</h4>
                    <p>Classic arcade sounds including movement effects, power pellet activation, ghost consumption, and background music with volume controls.</p>
                </div>
                
                <div class="feature-card">
                    <h4>⚙️ Game Settings</h4>
                    <p>Customizable difficulty levels, speed settings, sound controls, and key binding options. Save/load game state functionality.</p>
                </div>
            </div>
        </section>
        
        <section id="gameplay" class="section">
            <h2>🎮 Gameplay Mechanics</h2>
            
            <h3>🎯 Objective</h3>
            <p>Guide Pacman through the maze to eat all dots while avoiding the four colored ghosts. Complete each level by consuming all dots and advance to increasingly challenging stages.</p>
            
            <h3>🟡 Power Pellets</h3>
            <p>Collect large flashing dots to temporarily turn ghosts blue and vulnerable. During this "frightened" state, Pacman can eat ghosts for bonus points. The effect duration decreases as levels progress.</p>
            
            <h3>🍎 Bonus Fruits</h3>
            <p>Special items appear periodically in the center of the maze. Collect them for extra points and bonuses. Fruit types change based on the current level.</p>
            
            <h3>👻 Ghost Behavior</h3>
            <ul style="margin-left: 20px;">
                <li><strong>Blinky (Red):</strong> Directly chases Pacman with increasing speed</li>
                <li><strong>Pinky (Pink):</strong> Ambushes by targeting positions ahead of Pacman</li>
                <li><strong>Inky (Cyan):</strong> Uses complex positioning relative to Blinky and Pacman</li>
                <li><strong>Clyde (Orange):</strong> Switches between chase and scatter modes</li>
            </ul>
            
            <div class="screenshot-placeholder">
                <p>🖼️ Gameplay Screenshot</p>
                <p>Main game screen showing maze, Pacman, ghosts, and UI elements</p>
            </div>
        </section>
        
        <section id="controls" class="section">
            <h2>🎮 Game Controls</h2>
            
            <div class="controls-grid">
                <div class="control-item">
                    <div class="control-key">↑ W</div>
                    <p>Move Up</p>
                </div>
                <div class="control-item">
                    <div class="control-key">↓ S</div>
                    <p>Move Down</p>
                </div>
                <div class="control-item">
                    <div class="control-key">← A</div>
                    <p>Move Left</p>
                </div>
                <div class="control-item">
                    <div class="control-key">→ D</div>
                    <p>Move Right</p>
                </div>
                <div class="control-item">
                    <div class="control-key">SPACE</div>
                    <p>Pause Game</p>
                </div>
                <div class="control-item">
                    <div class="control-key">ESC</div>
                    <p>Main Menu</p>
                </div>
                <div class="control-item">
                    <div class="control-key">R</div>
                    <p>Restart Level</p>
                </div>
                <div class="control-item">
                    <div class="control-key">M</div>
                    <p>Toggle Sound</p>
                </div>
            </div>
            
            <h3>📱 Additional Controls</h3>
            <ul style="margin-left: 20px;">
                <li><strong>Enter:</strong> Confirm selection in menus</li>
                <li><strong>Tab:</strong> Toggle debug information</li>
                <li><strong>F1:</strong> Help screen</li>
                <li><strong>F11:</strong> Toggle fullscreen mode</li>
            </ul>
        </section>
        
        <section id="technical" class="section">
            <h2>⚙️ Technical Implementation</h2>
            
            <h3>🏗️ Architecture</h3>
            <p>The game follows a modular architecture with separate components for graphics rendering, game logic, AI behavior, and input handling. The main game loop handles updates at 60 FPS for smooth gameplay.</p>
            
            <div class="code-block">
// Main game loop structure
void iDraw() {
    // Clear screen
    iClear();
    
    // Render game elements
    drawMaze();
    drawPacman();
    drawGhosts();
    drawUI();
    
    // Update game state
    updateGameLogic();
}</div>
            
            <h3>🎨 Graphics System</h3>
            <ul style="margin-left: 20px;">
                <li><strong>iGraphics Library:</strong> OpenGL-based 2D graphics rendering</li>
                <li><strong>Sprite Animation:</strong> Frame-based animation system for characters</li>
                <li><strong>Particle Effects:</strong> Custom particle system for visual feedback</li>
                <li><strong>UI Components:</strong> Custom-drawn interface elements</li>
            </ul>
            
            <h3>🤖 AI Implementation</h3>
            <p>Ghost AI uses pathfinding algorithms and state machines to create challenging but fair gameplay. Each ghost has distinct targeting strategies implemented through different algorithms.</p>
            
            <div class="code-block">
// Ghost AI state machine
typedef enum {
    SCATTER,
    CHASE,
    FRIGHTENED,
    EATEN
} GhostState;

void updateGhostAI(Ghost* ghost) {
    switch(ghost->state) {
        case CHASE:
            moveTowardTarget(ghost, getTargetPosition(ghost));
            break;
        case SCATTER:
            moveTowardTarget(ghost, ghost->homeCorner);
            break;
        // ... other states
    }
}</div>
            
            <h3>💾 Data Management</h3>
            <ul style="margin-left: 20px;">
                <li><strong>Game State:</strong> Centralized state management system</li>
                <li><strong>Level Data:</strong> Maze layouts stored in structured format</li>
                <li><strong>High Scores:</strong> Persistent storage using file I/O</li>
                <li><strong>Settings:</strong> Configuration file for user preferences</li>
            </ul>
        </section>
        
        <section id="installation" class="section">
            <h2>🛠️ Installation & Setup</h2>
            
            <h3>📋 Prerequisites</h3>
            <ul style="margin-left: 20px;">
                <li>C Compiler (GCC recommended)</li>
                <li>iGraphics Library</li>
                <li>OpenGL libraries</li>
                <li>Windows/Linux compatible system</li>
            </ul>
            
            <h3>⚡ Quick Start</h3>
            <div class="code-block">
# Clone the repository
git clone https://github.com/Ratulhasanbuet/CSE-102-IGRAPHICS-PROJECT.git

# Navigate to project directory
cd CSE-102-IGRAPHICS-PROJECT

# Compile the project
gcc -o pacman *.c -liGraphics -lglut32 -lopengl32 -lglu32

# Run the game
./pacman</div>
            
            <h3>🔧 Setup Instructions</h3>
            <ol style="margin-left: 20px;">
                <li>Install iGraphics library and dependencies</li>
                <li>Configure your IDE with OpenGL libraries</li>
                <li>Build the project using provided makefile</li>
                <li>Run the executable to start the game</li>
            </ol>
            
            <h3>🐛 Troubleshooting</h3>
            <ul style="margin-left: 20px;">
                <li><strong>Graphics not displaying:</strong> Verify OpenGL drivers are installed</li>
                <li><strong>Compilation errors:</strong> Check iGraphics library path</li>
                <li><strong>Sound issues:</strong> Ensure audio drivers are up to date</li>
                <li><strong>Performance problems:</strong> Adjust graphics settings in config file</li>
            </ul>
        </section>
        
        <section id="source" class="section">
            <h2>📁 Source Code Structure</h2>
            
            <div class="code-block">
CSE-102-IGRAPHICS-PROJECT/
├── src/
│   ├── main.c              # Main game loop and initialization
│   ├── pacman.c            # Pacman character logic
│   ├── ghost.c             # Ghost AI implementation
│   ├── maze.c              # Maze rendering and collision
│   ├── ui.c                # User interface components
│   ├── sound.c             # Audio system
│   └── utils.c             # Utility functions
├── assets/
│   ├── images/             # Sprite images
│   ├── sounds/             # Audio files
│   └── levels/             # Level data files
├── docs/
│   ├── README.md           # Project documentation
│   └── manual.pdf          # User manual
├── iGraphics/              # iGraphics library files
└── Makefile               # Build configuration</div>
            
            <h3>🔍 Key Files</h3>
            <ul style="margin-left: 20px;">
                <li><strong>main.c:</strong> Entry point, initialization, and main game loop</li>
                <li><strong>pacman.c:</strong> Player character movement and collision detection</li>
                <li><strong>ghost.c:</strong> AI behavior implementation for all four ghosts</li>
                <li><strong>maze.c:</strong> Maze generation, rendering, and pathfinding</li>
                <li><strong>ui.c:</strong> Menu system, HUD, and user interface</li>
                <li><strong>sound.c:</strong> Audio playback and sound effect management</li>
            </ul>
            
            <h3>📊 Project Statistics</h3>
            <div class="stats-grid">
                <div class="stat-card">
                    <div class="stat-number">~1200</div>
                    <div class="stat-label">Lines of Code</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">8</div>
                    <div class="stat-label">Source Files</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">25+</div>
                    <div class="stat-label">Functions</div>
                </div>
                <div class="stat-card">
                    <div class="stat-number">4</div>
                    <div class="stat-label">Game Modes</div>
                </div>
            </div>
        </section>
        
        <div class="author-info">
            <h3>👨‍💻 Developer Information</h3>
            <p><strong>Name:</strong> Ratul Hasan</p>
            <p><strong>Course:</strong> CSE-102 (Structured Programming Language)</p>
            <p><strong>Institution:</strong> Bangladesh University of Engineering and Technology (BUET)</p>
            <p><strong>GitHub:</strong> <a href="https://github.com/Ratulhasanbuet" style="color: #333;">@Ratulhasanbuet</a></p>
            <p><strong>Project:</strong> iGraphics Pacman Game Implementation</p>
        </div>
    </div>
    
    <script>
        // Smooth scrolling for navigation links
        document.querySelectorAll('a[href^="#"]').forEach(anchor => {
            anchor.addEventListener('click', function (e) {
                e.preventDefault();
                const target = document.querySelector(this.getAttribute('href'));
                if (target) {
                    target.scrollIntoView({
                        behavior: 'smooth',
                        block: 'start'
                    });
                }
            });
        });
        
        // Add fade-in animation to sections
        const sections = document.querySelectorAll('.section');
        const observer = new IntersectionObserver((entries) => {
            entries.forEach(entry => {
                if (entry.isIntersecting) {
                    entry.target.style.opacity = '1';
                    entry.target.style.transform = 'translateY(0)';
                }
            });
        });
        
        sections.forEach(section => {
            section.style.opacity = '0';
            section.style.transform = 'translateY(20px)';
            section.style.transition = 'opacity 0.6s ease, transform 0.6s ease';
            observer.observe(section);
        });
        
        // Initialize first section
        if (sections.length > 0) {
            sections[0].style.opacity = '1';
            sections[0].style.transform = 'translateY(0)';
        }
    </script>
</body>
</html>