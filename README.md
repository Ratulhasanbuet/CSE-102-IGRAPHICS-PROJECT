<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>PAC-MAN: Retro Reimagined — Full Source & Docs</title>
  <style>
    body {
      background: #121212;
      color: #f0f0f0;
      font-family: 'Segoe UI', sans-serif;
      margin: 0 auto;
      max-width: 980px;
      padding: 1rem;
      line-height: 1.5;
    }
    h1, h2, h3 {
      color: #ffcc00;
      margin-top: 1.5rem;
    }
    h1 { text-align: center; }
    nav {
      text-align: center;
      margin: 1rem 0;
    }
    nav a {
      color: #00ffff;
      text-decoration: none;
      margin: 0 .5rem;
      font-weight: bold;
    }
    nav a:hover { text-decoration: underline; }
    section { margin-bottom: 2rem; }
    table {
      width: 100%;
      border-collapse: collapse;
      margin: 1rem 0;
      background: #1e1e1e;
    }
    th, td {
      border: 1px solid #444;
      padding: .5rem;
    }
    th {
      background: #2a2a2a;
      color: #00ffff;
    }
    tr:nth-child(even) { background: #202020; }
    ul, ol {
      margin: .5rem 0 1rem 1.5rem;
    }
    code {
      background: #292929;
      color: #ffcc00;
      padding: 2px 4px;
      border-radius: 3px;
      font-size: .95em;
    }
    pre {
      background: #1e1e1e;
      padding: 1rem;
      overflow-x: auto;
      border-radius: 4px;
      line-height: 1.3;
      font-size: .85em;
    }
    details {
      margin: 1rem 0;
      background: #181818;
      border: 1px solid #333;
      border-radius: 4px;
      padding: .5rem;
    }
    summary {
      cursor: pointer;
      font-weight: bold;
      color: #00ffff;
    }
    figure.special-thanks {
      margin: 1rem 0;
      padding: .75rem;
      background: #1f1f1f;
      border: 1px solid #333;
      border-radius: 6px;
      text-align: center;
    }
    figure.special-thanks img {
      max-width: 100%;
      height: auto;
      border-radius: 4px;
    }
    figure.special-thanks figcaption {
      margin-top: .5rem;
      font-size: .9em;
      color: #ccc;
      font-style: italic;
    }
    footer {
      text-align: center;
      font-size: .85em;
      color: #888;
      margin: 2rem 0;
    }
  </style>
</head>
<body>

  <h1>PAC-MAN: Retro Reimagined</h1>
  <p style="text-align:center; color:#aaa; margin-bottom:2rem;">
    Built in C with <code>iGraphics.h</code> ─ full source, docs & AI behaviors.
  </p>

  <section id="authors">
    <h2>Authors & Credits</h2>
    <ul>
      <li><strong>Md Ratul Hasan</strong> — CSE'24</li>
      <li><strong>Hasibul Islam</strong> — CSE'24</li>
      <li>Guided by Abdur Rafi</li>
    </ul>

    <figure class="special-thanks">
      <img src="images/special_thanks.png" 
           alt="Special Thanks to Abdur Rashid Tyshar, Anwarul Bashir Shuaib, Kazi Rakibul Hasan" />
      <figcaption>
        “Special thanks to<br>
        Abdur Rashid Tyshar (CSE-16, BUET)<br>
        Anwarul Bashir Shuaib (CSE-18, BUET)<br>
        Kazi Rakibul Hasan (CSE-18, BUET)<br><br>
        ‘At first, I had no idea how to get started. Later, after watching my seniors’ videos 
        and looking at their code, I got an idea about how to approach it. I followed some 
        of the complex parts from their code. A heartfelt thank you to them for their support.’
      </figcaption>
    </figure>
  </section>

  <nav>
    <a href="#overview">Overview</a> |
    <a href="#mechanics">Mechanics</a> |
    <a href="#ui">UI & Menus</a> |
    <a href="#mazes">Mazes & Themes</a> |
    <a href="#difficulty">Difficulty</a> |
    <a href="#scoring">Scoring</a> |
    <a href="#ghosts">Ghost AI</a> |
    <a href="#code">Source</a>
  </nav>

  <!-- Additional sections (Overview, Mechanics, UI & Menus, etc.) go here -->

  <footer>
    Made by Ratul 🎯 • “Let’s make arcades great again!”<br/>
    Powered by precision, obsession &amp; <code>iGraphics.h</code>
  </footer>

</body>
</html>
