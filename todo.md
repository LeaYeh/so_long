## Schedule plan (deadline 11/05)
- [x] setup devlop env
- [ ](1hr) folder strucure
- [ ](0.5d) parsing map
    - add gnl into library
    - read by gnl
    - error handling
- [ ](0.5d) window
    - api study
        - close
        - init with size
        - hook event
        - loop animation
    - init window
    - destroy window
- [ ](1d) structure design
    - global varible
    - player
    - enemy
    - gate
    - game
    - screen
    - camera
    - bean shot
- [ ](3d) interactive
    - bind keyboard
    - enemy searching mechanism
    - player jump mechanism
    - player attact mechanism
- [ ](2d) render
    - static
        - backfround
        - wall
    - animation
    
## structure design
### general
- position
    - x
    - y
- game
    - void *mlx
    - void *window
    - char **map
    - int fps
    - int w_width
    - int w_height
    - int g_width
    - int g_height
    
    - t_player *player
    - t_monster **monster
- camera

### player
- pixel position
    - position
- direction
    - bool (face left or right)
- body range
    - 4 corner (position)
        - top-left
        - top-right
        - bottom-left
        - bottom-right
- action code
- life number