#pragma once

#define SEPARATOR "----------------------------------------------------------------\n"
#define ART "		  _____          __   __        \n		 |_   _|__ ___ _ \\ \\ / /__ _ _  \n		   | |/ -_) _ \\ '_\\ V / -_) '_| \n		   |_|\\___\\___/_|  \\_/\\___|_|   \n"

typedef void* font;

class System
{	
	System() {}
	System(System&) {}
	void operator=(System&) {}
	
	static font Times_New_Roman;
	static char*	m_title;
	static int		m_width, m_height;
	static int		m_graphic;

	static float m_from_x, m_to_x;
	static float m_from_y, m_to_y;
	static float m_grid_percision;

	static float m_var_a, m_sigma, m_freedom_power;
	static float m_norm_a, m_norm_b;
	static float m_alpha;


	static void Render(void);
	static void Reshape(int _w, int _h);
	static void KeyboardIvent(unsigned char _key, int _x, int _y);
	//Drawing coo
	static void DrawAxis(void);
	static void DrawGrid(void);
	static void DrawCooLimits(void);
	//Graphics funcs
	static float RavnomernoeRaspredelenieFunc(const float& _x);
	static float NormalnoeRaspredelenieFunc(const float& _x);
	static float RaspredeleneReleya(const float& _x);
	static float RaspredelenieXiKvadrat(const float& _x);
	static float RaspredeleniePokazatelnoe(const float& _x);
	static void RenderBitmapString(const float& _x, const float& _y, font _font, char* _str);
public:
	static bool InitGraphicSys(const int& _w, const int& _h, const char* _title, int& _argc, char** _argv);
	static bool CreateGraphicWindow(void);
	static void StartGraphics(void);
	static void SetAxis(const float& _from_x, const float& _to_x, const float& _from_y, const float& _to_y, const float& _grid_percision);
};

