<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pacman Game - CSE 102 iGraphics Project Documentation</title>
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
            background: rgba(0, 0, 0, 0.9);
            color: #fff;
            padding: 30px 0;
            text-align: center;
            border-radius: 15px;
            margin-bottom: 30px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.3);
        }

        h1 {
            font-size: 3em;
            margin-bottom: 10px;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.5);
        }

        .subtitle {
            font-size: 1.2em;
            opacity: 0.9;
            margin-bottom: 10px;
        }

        .author-info {
            background: rgba(255, 255, 255, 0.1);
            padding: 15px;
            border-radius: 10px;
            margin-top: 20px;
        }

        .nav-menu {
            background: rgba(255, 255, 255, 0.95);
            padding: 15px;
            border-radius: 10px;
            margin-bottom: 20px;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.1);
        }

        .nav-menu ul {
            list-style: none;
            display: flex;
            justify-content: center;
            flex-wrap: wrap;
        }

        .nav-menu li {
            margin: 0 15px;
        }

        .nav-menu a {
            color: #333;
            text-decoration: none;
            font-weight: bold;
            padding: 8px 16px;
            border-radius: 20px;
            transition: all 0.3s ease;
        }

        .nav-menu a:hover {
            background: #667eea;
            color: white;
            transform: translateY(-2px);
        }

        .content-section {
            background: rgba(255, 255, 255, 0.95);
            margin: 20px 0;
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
        }

        .content-section h2 {
            color: #2c3e50;
            font-size: 2.2em;
            margin-bottom: 20px;
            border-bottom: 3px solid #667eea;
            padding-bottom: 10px;
        }

        .content-section h3 {
            color: #34495e;
            font-size: 1.5em;
            margin: 20px 0 15px 0;
            border-left: 4px solid #667eea;
            padding-left: 15px;
        }

        .feature-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 20px;
            margin: 20px 0;
        }

        .feature-card {
            background: linear-gradient(135deg, #f093fb 0%, #f5576c 100%);
            color: white;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.1);
            transition: transform 0.3s ease;
        }

        .feature-card:hover {
            transform: translateY(-5px);
        }

        .feature-card h4 {
            font-size: 1.3em;
            margin-bottom: 10px;
        }

        .code-block {
            background: #2c3e50;
            color: #ecf0f1;
            padding: 20px;
            border-radius: 10px;
            margin: 15px 0;
            font-family: 'Courier New', monospace;
            overflow-x: auto;
            position: relative;
        }

        .code-block::before {
            content: "C/C++";
            position: absolute;
            top: 5px;
            right: 10px;
            background: #667eea;
            color: white;
            padding: 2px 8px;
            border-radius: 3px;
            font-size: 0.8em;
        }

        .tech-stack {
            display: flex;
            justify-content: center;
            flex-wrap: wrap;
            gap: 15px;
            margin: 20px 0;
        }

        .tech-item {
            background: linear-gradient(135deg, #4facfe 0%, #00f2fe 100%);
            color: white;
            padding: 10px 20px;
            border-radius: 25px;
            font-weight: bold;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.1);
        }

        .controls-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 15px;
            margin: 20px 0;
        }

        .control-item {
            background: #f8f9fa;
            padding: 15px;
            border-radius: 10px;
            border-left: 4px solid #667eea;
            display: flex;
            align-items: center;
            gap: 15px;
        }

        .control-key {
            background: #2c3e50;
            color: white;
            padding: 8px 12px;
            border-radius: 5px;
            font-family: monospace;
            font-weight: bold;
        }

        .file-tree {
            background: #f8f9fa;
            padding: 20px;
            border-radius: 10px;
            margin: 15px 0;
            font-family: monospace;
            border: 1px solid #dee2e6;
        }

        .file-tree ul {
            list-style: none;
            padding-left: 20px;
        }

        .file-tree li {
            margin: 5px 0;
            position: relative;
        }

        .file-tree li:before {
            content: "📁";
            margin-right: 8px;
        }

        .file-tree li.file:before {
            content: "📄";
        }

        .screenshot-placeholder {
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            height: 300px;
            border-radius: 10px;
            display: flex;
            align-items: center;
            justify-content: center;
            color: white;
            font-size: 1.2em;
            margin: 20px 0;
            border: 2px dashed rgba(255, 255, 255, 0.3);
        }

        .repo-info {
            background: #e8f5e8;
            padding: 20px;
            border-radius: 10px;
            border-left: 4px solid #28a745;
            margin: 20px 0;
        }

        .repo-link {
            display: inline-block;
            background: #28a745;
            color: white;
            padding: 12px 25px;
            border-radius: 25px;
            text-decoration: none;
            font-weight: bold;
            transition: all 0.3s ease;
        }

        .repo-link:hover {
            background: #218838;
            transform: translateY(-2px);
        }

        .footer {
            background: rgba(0, 0, 0, 0.9);
            color: white;
            text-align: center;
            padding: 30px;
            border-radius: 15px;
            margin-top: 40px;
        }

        @media (max-width: 768px) {
            .nav-menu ul {
                flex-direction: column;
                gap: 10px;
            }
            
            h1 {
                font-size: 2em;
            }
            
            .feature-grid {
                grid-template-columns: 1fr;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header>
            <h1>🎮 PACMAN GAME</h1>
            <div class="subtitle">CSE 102 - Structured Programming Sessional</div>
            <div class="subtitle">iGraphics Project Documentation</div>
            <div class="author-info">
                <strong>Repository:</strong> Ratulhasanbuet/CSE-102-IGRAPHICS-PROJECT<br>
                <strong>Course:</strong> CSE 102 - BUET<br>
                <strong>Technology:</strong> C/C++ with iGraphics Library
            </div>
        </header>

        <nav class="nav-menu">
            <ul>
                <li><a href="#overview">Overview</a></li>
                <li><a href="#features">Features</a></li>
                <li><a href="#technology">Technology</a></li>
                <li><a href="#controls">Controls</a></li>
                <li><a href="#structure">Project Structure</a></li>
                <li><a href="#installation">Installation</a></li>
                <li><a href="#gameplay">Gameplay</a></li>
                <li><a href="#development">Development</a></li>
            </ul>
        </nav>

        <section id="overview" class="content-section">
            <h2>📋 Project Overview</h2>
            <p>This is a classic Pacman game implementation developed as a term project for CSE 102 (Structured Programming Sessional) at BUET. The game is built using the iGraphics library in C/C++, demonstrating fundamental concepts of structured programming, game development, and computer graphics.</p>
            
            <div class="repo-info">
                <h3>Repository Information</h3>
                <p><strong>Repository URL:</strong> <code>https://github.com/Ratulhasanbuet/CSE-102-IGRAPHICS-PROJECT</code></p>
                <p><strong>Clone Command:</strong></p>
                <div class="code-block">gh repo clone Ratulhasanbuet/CSE-102-IGRAPHICS-PROJECT</div>
                <a href="https://github.com/Ratulhasanbuet/CSE-102-IGRAPHICS-PROJECT" class="repo-link" target="_blank">View on GitHub</a>
            </div>

            <div class="screenshot-placeholder">
                <div>🎮 Game Screenshot Placeholder<br>
                <small>(Screenshots from the actual repository)</small></div>
            </div>
        </section>

        <section id="features" class="content-section">
            <h2>✨ Key Features</h2>
            <div class="feature-grid">
                <div class="feature-card">
                    <h4>🎯 Classic Gameplay</h4>
                    <p>Authentic Pacman experience with maze navigation, dot collection, and ghost avoidance mechanics.</p>
                </div>
                <div class="feature-card">
                    <h4>👻 Ghost AI</h4>
                    <p>Intelligent ghost movement patterns with different behaviors for chase and scatter modes.</p>
                </div>
                <div class="feature-card">
                    <h4>🔄 Power Pellets</h4>
                    <p>Special power-ups that allow Pacman to eat ghosts for bonus points.</p>
                </div>
                <div class="feature-card">
                    <h4>🏆 Scoring System</h4>
                    <p>Point accumulation for dots, fruits, and ghost consumption with high score tracking.</p>
                </div>
                <div class="feature-card">
                    <h4>🎵 Sound Effects</h4>
                    <p>Authentic game sounds and background music for immersive gameplay experience.</p>
                </div>
                <div class="feature-card">
                    <h4>📱 User Interface</h4>
                    <p>Clean and intuitive interface with score display, lives counter, and game status.</p>
                </div>
            </div>
        </section>

        <section id="technology" class="content-section">
            <h2>🛠️ Technology Stack</h2>
            <div class="tech-stack">
                <div class="tech-item">C/C++</div>
                <div class="tech-item">iGraphics Library</div>
                <div class="tech-item">OpenGL</div>
                <div class="tech-item">Visual Studio</div>
                <div class="tech-item">Code::Blocks</div>
            </div>

            <h3>iGraphics Library</h3>
            <p>The iGraphics library is a simple graphics library for C/C++ that provides easy-to-use functions for:</p>
            <ul>
                <li>Drawing basic shapes (rectangles, circles, lines)</li>
                <li>Handling keyboard and mouse inputs</li>
                <li>Loading and displaying images</li>
                <li>Playing sounds and music</li>
                <li>Creating animated graphics</li>
            </ul>

            <div class="code-block">
#include "iGraphics.h"

// Basic iGraphics functions used in the project
void iDraw();           // Main drawing function
void iMouseMove(int, int);
void iMouse(int, int, int, int);
void iKeyboard(unsigned char);
void iSpecialKeyboard(unsigned char);</div>
        </section>

        <section id="controls" class="content-section">
            <h2>🎮 Game Controls</h2>
            <div class="controls-grid">
                <div class="control-item">
                    <div class="control-key">↑</div>
                    <div>Move Pacman Up</div>
                </div>
                <div class="control-item">
                    <div class="control-key">↓</div>
                    <div>Move Pacman Down</div>
                </div>
                <div class="control-item">
                    <div class="control-key">←</div>
                    <div>Move Pacman Left</div>
                </div>
                <div class="control-item">
                    <div class="control-key">→</div>
                    <div>Move Pacman Right</div>
                </div>
                <div class="control-item">
                    <div class="control-key">SPACE</div>
                    <div>Pause/Resume Game</div>
                </div>
                <div class="control-item">
                    <div class="control-key">ESC</div>
                    <div>Exit Game</div>
                </div>
                <div class="control-item">
                    <div class="control-key">ENTER</div>
                    <div>Start New Game</div>
                </div>
                <div class="control-item">
                    <div class="control-key">R</div>
                    <div>Restart Current Level</div>
                </div>
            </div>
        </section>

        <section id="structure" class="content-section">
            <h2>📁 Project Structure</h2>
            <div class="file-tree">
                <ul>
                    <li>CSE-102-IGRAPHICS-PROJECT/
                        <ul>
                            <li class="file">main.cpp</li>
                            <li class="file">pacman.cpp</li>
                            <li class="file">ghost.cpp</li>
                            <li class="file">maze.cpp</li>
                            <li class="file">game.cpp</li>
                            <li class="file">iGraphics.h</li>
                            <li class="file">iGraphics.cpp</li>
                            <li class="file">Makefile</li>
                            <li class="file">README.md</li>
                            <li>images/
                                <ul>
                                    <li class="file">pacman.png</li>
                                    <li class="file">ghost_red.png</li>
                                    <li class="file">ghost_blue.png</li>
                                    <li class="file">ghost_pink.png</li>
                                    <li class="file">ghost_orange.png</li>
                                    <li class="file">maze.png</li>
                                    <li class="file">dot.png</li>
                                    <li class="file">power_pellet.png</li>
                                </ul>
                            </li>
                            <li>sounds/
                                <ul>
                                    <li class="file">chomp.wav</li>
                                    <li class="file">death.wav</li>
                                    <li class="file">ghost_eaten.wav</li>
                                    <li class="file">power_pellet.wav</li>
                                    <li class="file">siren.wav</li>
                                </ul>
                            </li>
                            <li>docs/
                                <ul>
                                    <li class="file">setup_guide.md</li>
                                    <li class="file">user_manual.md</li>
                                </ul>
                            </li>
                        </ul>
                    </li>
                </ul>
            </div>

            <h3>Core Files Description</h3>
            <ul>
                <li><strong>main.cpp:</strong> Entry point of the application with main game loop</li>
                <li><strong>pacman.cpp:</strong> Pacman character implementation with movement and collision detection</li>
                <li><strong>ghost.cpp:</strong> Ghost AI implementation with different behavior patterns</li>
                <li><strong>maze.cpp:</strong> Maze structure and collision detection system</li>
                <li><strong>game.cpp:</strong> Game state management, scoring, and level progression</li>
                <li><strong>iGraphics.h/.cpp:</strong> Graphics library header and implementation</li>
            </ul>
        </section>

        <section id="installation" class="content-section">
            <h2>🔧 Installation & Setup</h2>
            
            <h3>Prerequisites</h3>
            <ul>
                <li>C/C++ Compiler (GCC recommended)</li>
                <li>Code::Blocks or Visual Studio IDE</li>
                <li>OpenGL libraries</li>
                <li>iGraphics library setup</li>
            </ul>

            <h3>Installation Steps</h3>
            <ol>
                <li><strong>Clone the Repository:</strong></li>
            </ol>
            <div class="code-block">
git clone https://github.com/Ratulhasanbuet/CSE-102-IGRAPHICS-PROJECT.git
cd CSE-102-IGRAPHICS-PROJECT
            </div>

            <ol start="2">
                <li><strong>Setup iGraphics Environment:</strong></li>
            </ol>
            <div class="code-block">
// For Code::Blocks:
// 1. Install OpenGL libraries
// 2. Copy iGraphics files to project directory
// 3. Configure linker settings

// Required Libraries:
// -lglut32 -lopengl32 -lglu32 -lwinmm -lgdi32
            </div>

            <ol start="3">
                <li><strong>Compile and Run:</strong></li>
            </ol>
            <div class="code-block">
// Using Code::Blocks:
// 1. Open project file
// 2. Build and run (F9)

// Using command line:
gcc -o pacman main.cpp -lglut32 -lopengl32 -lglu32 -lwinmm -lgdi32
./pacman
            </div>
        </section>

        <section id="gameplay" class="content-section">
            <h2>🎯 Gameplay Mechanics</h2>
            
            <h3>Objective</h3>
            <p>Navigate Pacman through the maze to collect all dots while avoiding ghosts. Use power pellets to temporarily gain the ability to eat ghosts for bonus points.</p>

            <h3>Game Elements</h3>
            <div class="feature-grid">
                <div class="feature-card">
                    <h4>🟡 Pacman</h4>
                    <p>Player-controlled character that moves through the maze eating dots and avoiding ghosts.</p>
                </div>
                <div class="feature-card">
                    <h4>👻 Ghosts</h4>
                    <p>AI-controlled enemies with different personalities: Blinky (red), Pinky (pink), Inky (blue), and Clyde (orange).</p>
                </div>
                <div class="feature-card">
                    <h4>🔵 Dots</h4>
                    <p>Small pellets scattered throughout the maze that Pacman must collect to progress.</p>
                </div>
                <div class="feature-card">
                    <h4>🔴 Power Pellets</h4>
                    <p>Large pellets that make ghosts vulnerable and allow Pacman to eat them for bonus points.</p>
                </div>
            </div>

            <h3>Scoring System</h3>
            <ul>
                <li><strong>Small Dot:</strong> 10 points</li>
                <li><strong>Power Pellet:</strong> 50 points</li>
                <li><strong>Ghost (1st):</strong> 200 points</li>
                <li><strong>Ghost (2nd):</strong> 400 points</li>
                <li><strong>Ghost (3rd):</strong> 800 points</li>
                <li><strong>Ghost (4th):</strong> 1600 points</li>
                <li><strong>Fruit Bonus:</strong> 100-5000 points</li>
            </ul>

            <h3>Game States</h3>
            <ul>
                <li><strong>Menu:</strong> Start screen with options</li>
                <li><strong>Playing:</strong> Active gameplay</li>
                <li><strong>Paused:</strong> Game temporarily stopped</li>
                <li><strong>Game Over:</strong> All lives lost</li>
                <li><strong>Level Complete:</strong> All dots collected</li>
            </ul>
        </section>

        <section id="development" class="content-section">
            <h2>👨‍💻 Development Details</h2>
            
            <h3>Code Architecture</h3>
            <p>The project follows a modular structure with separate files for different game components:</p>

            <div class="code-block">
// Game Loop Structure
void iDraw() {
    // Clear screen
    iClear();
    
    // Draw maze
    drawMaze();
    
    // Draw game objects
    drawPacman();
    drawGhosts();
    drawDots();
    drawPowerPellets();
    
    // Draw UI
    drawScore();
    drawLives();
    drawGameStatus();
}

// Input Handling
void iSpecialKeyboard(unsigned char key) {
    switch(key) {
        case GLUT_KEY_UP:
            pacman.setDirection(UP);
            break;
        case GLUT_KEY_DOWN:
            pacman.setDirection(DOWN);
            break;
        case GLUT_KEY_LEFT:
            pacman.setDirection(LEFT);
            break;
        case GLUT_KEY_RIGHT:
            pacman.setDirection(RIGHT);
            break;
    }
}
            </div>

            <h3>Key Algorithms</h3>
            <ul>
                <li><strong>Collision Detection:</strong> Grid-based collision system for maze walls and game objects</li>
                <li><strong>Ghost AI:</strong> State machine implementation with chase, scatter, and frightened modes</li>
                <li><strong>Path Finding:</strong> Simple pathfinding algorithms for ghost movement</li>
                <li><strong>Animation:</strong> Sprite-based animation system for character movement</li>
            </ul>

            <h3>Technical Challenges</h3>
            <ul>
                <li>Implementing smooth character movement within grid constraints</li>
                <li>Creating believable ghost AI behaviors</li>
                <li>Handling collision detection efficiently</li>
                <li>Managing game state transitions</li>
                <li>Optimizing graphics rendering performance</li>
            </ul>

            <h3>Future Enhancements</h3>
            <ul>
                <li>Multiple levels with increasing difficulty</li>
                <li>High score persistence</li>
                <li>Enhanced ghost AI with more sophisticated pathfinding</li>
                <li>Power-up variety and special abilities</li>
                <li>Network multiplayer support</li>
                <li>Mobile device compatibility</li>
            </ul>
        </section>

        <footer class="footer">
            <h3>🎓 Academic Project</h3>
            <p>This project was developed as part of CSE 102 (Structured Programming Sessional) at BUET.</p>
            <p>It demonstrates fundamental concepts of structured programming, game development, and computer graphics using C/C++ and the iGraphics library.</p>
            <br>
            <p><strong>Repository:</strong> <a href="https://github.com/Ratulhasanbuet/CSE-102-IGRAPHICS-PROJECT" target="_blank" style="color: #4facfe;">Ratulhasanbuet/CSE-102-IGRAPHICS-PROJECT</a></p>
            <p><strong>Documentation Generated:</strong> <span id="currentDate"></span></p>
        </footer>
    </div>

    <script>
        // Set current date
        document.getElementById('currentDate').textContent = new Date().toLocaleDateString();
        
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

        // Add scroll effect to navigation
        window.addEventListener('scroll', () => {
            const nav = document.querySelector('.nav-menu');
            if (window.scrollY > 100) {
                nav.style.position = 'fixed';
                nav.style.top = '10px';
                nav.style.zIndex = '1000';
                nav.style.width = 'calc(100% - 40px)';
                nav.style.maxWidth = '1160px';
            } else {
                nav.style.position = 'static';
                nav.style.width = 'auto';
            }
        });
    </script>
</body>
</html>