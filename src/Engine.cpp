#include "..\include\Engine.h" //Includes the Engine header

Engine::Engine()
{

	bg.setSize(Vector2f(size, size)); //Sets the size of the bg shape
	bg.setFillColor(Color::White);  //Sets the Color
	bg.setOutlineColor(Color::Black);  //Sets the color of the outline
	bg.setOutlineThickness(1);  // Sets the Thickness of the outline

	window.create(VideoMode(Ww, Wh), "SFML Snake"); // Creates window
	window.setFramerateLimit(10); //Sets the frame rate limit to 10. This controls the speed of the game.
	//A higher framerate would make the snake move faster
}

void Engine::Run() {

	apple.SpawnFood(); // Runs the SpawnFood method of the Food class.
	// This will set new coordinates for the apple object

	while (window.isOpen()) { // Run until the window is closed
		Event event; //Checks all user events
		while (window.pollEvent(event)) {

			// If the user presses the close button
			if (event.type == Event::Closed)
				window.close(); //Close the window
		}

		window.clear();

		Boundaries(); //Runs Boundaries()
		Input();  //Runs Input()
		drawToScreen();  //Runs drawTpScreen ()
		EngGame(window); // Runs Endgame()
	}

}

void Engine::EngGame(RenderWindow& window)
{

	if (snake.getSx() > (Ww - size)) { //If the snake goes beyond the right wall
		window.close(); //The window closes
	}
	else if (snake.getSx() < 0) { //If the snake goes beyond the left wall
		window.close(); //The window closes
	}
	else if (snake.getSy() > Wh - size) {  //If the snake goes beyond the bottom wall
		window.close();  //The window closes
	}
	else if (snake.getSy() < 0) {  //If the snake goes beyond the top wall
		window.close();  //The window closes
	}
}

void Engine::drawToScreen()
{

	/*Font and text sizes, styles, Color, etc.*/
/*****************************************************/
	string str1 = to_string(points);                 // Converts points to a string so that it can be shown on the window
	font.loadFromFile("Fonts/arial.ttf");            //
	if (!font.loadFromFile("Fonts/arial.ttf"))       //
		throw("COULD NOT LOAD FONT");                //
	pointext.setFont(font);                          //
	pointext.setCharacterSize(30);                   //
	pointext.setFillColor(Color::Blue);              //
	pointext.setStyle(Text::Bold);                   //
	pointext.setString("Points: " + str1);           //
/****************************************************/

		/*This for loop will increment i and j 31 times(the number of rows and columns).
	Then it will draw bg to all those coords, making a grid, with every square being 20 px*/
	/*************************************************************************/
	for (int i = 0; i < 31; i++)                                         //
		for (int j = 0; j < 31; j++)                                     // 
		{                                                                //	
			bg.setPosition(i * 20, j * 20); // Sets the position of bg   // 
			window.draw(bg); //draws bg to the screen                    //
		}                                                                //
/************************************************************************/

	// Runs the SnakeEatSelf method of the Snake Class
	snake.SnakeEatSelf(window);  // This will calculate if the snake's head crosses the snake's body

	// Runs the tick() method of the Snake class
	snake.tick(window); // This will update the snakes size and position

	// Runs the drawSnake() method of the Snake class
	snake.drawSnake(window); // This will draw the snake's head and body to the window

	// Runs the drawFood() method of the Food class
	apple.drawFood(window); // This will draw the food to the window

	window.draw(pointext);

	//Displays everything that's been drawn to the window
	window.display();
}

void Engine::Input() {

	if (Keyboard::isKeyPressed(Keyboard::Up) == true) { // If the User pressed the Up arrow
		if (snake.getdiry() != 1) { // And the snake isn't already going Down
			snake.snakeMovement(0, -1); // Changes the direction of the snake to Up
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) == true) {  // If the User pressed the Down arrow
		if (snake.getdiry() != -1) { // And the Snake isn't already going Up
			snake.snakeMovement(0, 1); // Changes the direction of the snake to Down
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) == true) {  // If the User pressed the Right arros
		if (snake.getdirx() != -1) { // And the snake isn't already going Left
			snake.snakeMovement(1, 0); // Changes the direction of the snake to Right
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left) == true) {  // If the User pressed the Left arrow
		if (snake.getdirx() != 1) { // And the snake isn't already going Right
			snake.snakeMovement(-1, 0); // Changes the direction of the snake to Left
		}
	}
}

void Engine::Boundaries() {
	snakehbounds = snake.snakehead.getGlobalBounds(); // Sets the Gloabl bound for snakehead
	foodbounds = apple.FShape.getGlobalBounds();  // Sets the Gloabl bound for FShape


	if (snakehbounds.intersects(foodbounds)) { // If the snake' head touches the food
		snake.snakehead.setFillColor(Color::Blue);  // Turns the head Blue
		snake.IncLength(); // Increments the length of the snake
		apple.SpawnFood(); // Spawns more food in a random location
		points++;
	}
	else {
		snake.snakehead.setFillColor(Color::Green); //Turns the head back to Green when the snake stops touching food.
	}

}