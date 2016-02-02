Crust Library
=============

What is this? It sounds yummy
-----------------------------

Crust is very similar to jQuery in its dynamicness, but for typed languages. 
The Crust core library is written in FreePascal and uses RTTI quite extensively.

This is what I'm going for:
- Dynamic
- Tiny
- Pizza analogies


Platforms: Windows, Mac, iOS
Supported languages: C, C++, (Free)Pascal


Crust is somewhere between being a graphics engine and a game engine. While it does not provide
window managing and you have to manage input and window by yourself, but on the other hand Crust
provides some game-specific functions and objects.


How does it work?
-----------------

Let's take a pizza analogy, because I've never seen anyone who didn't like pizza.

We need to have a base for a pizza, some awesome dough. Take anything you want or you like the most, 
like SDL, SFML, GLFW or even your own window manager. Crust itself does not provide any kind of window management.

The next thing you need is Crust. Import the library, take a look at the examples. It basically works like this:
	
	Crust::Sprite* sprite = new Crust::Sprite();
	sprite->attr("x", "50");
	sprite->attr("y", "50");
    // Every property can be accessed through the attr method
	char* spriteName = sprite->attr("name");
	int spriteId = sprite->attr("id");
	
Create your own topping (read game or other multimedia application).
