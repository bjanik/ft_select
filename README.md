# ft_select - UNIX Branch

by bjanik

Grade: 106/100

# Use 
./ft_select arg [arg2]...

Small program which takes argument and display them on the terminal using termcaps library.

### User can browse through by performing different actions :

        Use arrows to move through.
        
        Press Space key to select/unselected an argument
  
        Press Delete to delete the argument on which the cursor points to.
  
        Press Escape to quit the programm.
  
        Press Enter to display on Standard Output the list of selected arguments.
        
Exemple of use of ft_select:

ls `./ft_select *` will run ls command with all the arguments selected with ft_select

