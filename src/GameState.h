class GameState
{
	public:
		virtual void init() = 0;
		virtual void handleEvent(const SDL_Event &Event) = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
};
