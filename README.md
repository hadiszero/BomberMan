# BomberMan
BomberMan


Basic project setting. Input setting and handling. Add both cpp,bp gamemode and gameinstance

External assets:
Robot mesh and some related assets from ThirdPersonTemplate.
A beam particle from ContentExample.

Both of them are located in Content/ThirdParty folder


Time cost

For I'm not familiar with github, so I uploaded project to my own Perforce server first. Finally uploaded to github, so the timestamp can see on github is not real, but the commit steps are almost same(only merged some unimportant commits) to the commit steps of my perforce server, so you still can follow the step how I finish the project.

Basic setting and key setting: 0.5 hour
procedural generated map: 3 hours
Pan in/out camera: 1 hour
Bombs(normal bomb, remote controlled bomb): 1 hour
Pick up: 2 hour
Destructable walls and spawn pickups: 1 hour
Blast control(line trace and penalty): 1 hour
Blast effect(fire effects): 1 hour
Win conditions and UI: 2 hours
Others: 1 hour


For AI:
For the reason of AI system is a very complicated work and needs lots of time to polish, it seems difficult to finish in a couple of hours, so I didn't create AI for players, but I drawed an AI flowchart, which named AIFlowchart.png in the root folder (same folder as README.md), which discribes how to achieve an AI system.



How to play
1P: 

W: go up
A: go left
S: go down
D: go right

J: spawn a bomb
K: ignite a remote bomb(if you have)

2P:
Up Arrow: Go up
Left Arrow: Go left
Down Arrow: Go down
Right Arrow: Go right

Num 1: spawn a bomb
Num 2: ignite a remote bomb(if you have)
