# climenu
simple CLI menu library

# usage
create an object of climenu_t
set the count component as the amount of items in the menu, it should start with 1, not 0
allocate and fill in the items component with the strings for the items in the menu
call `menuselect(<your menu>)` on an integer, so something like this; `uint16_t selection = menuselect(menu);`
menuselect will print the items and prompt for your choice, negative numbers are not handled, so, -1 would be a really high number
