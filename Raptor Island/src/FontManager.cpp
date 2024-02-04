#include "FontManager.hpp"

FontManager *FontManager::instance = nullptr;

FontManager* FontManager::getInstance(void)
{
	if (instance == nullptr)
		instance = new FontManager();
	return (instance);
}

FontManager::FontManager(void)
{
	if (TTF_Init() == -1)
	{
		throw(ErrorHandler("Unable to initialize TTF: " + std::string(TTF_GetError()), __FILE__, __LINE__));
	}
	loadFonts();
}

FontManager::~FontManager(void)
{
	for (auto it = fonts.begin(); it != fonts.end(); ++it)
	{
		TTF_CloseFont(it->second);
	}
	fonts.clear();
	TTF_Quit();
}

void	FontManager::loadFonts(void)
{
	std::string fontPaths[2] = { "C:/Users/asus/source/repos/Raptor Island/assets/fonts/Bangers.ttf",
								"C:/Users/asus/source/repos/Raptor Island/assets/fonts/Mael.ttf" };
	for (auto path : fontPaths)
	{
		TTF_Font* font = nullptr;
		font = TTF_OpenFont(path.c_str(), 16);
		if (!font)
			throw(ErrorHandler("Unable to open font: " + std::string(TTF_GetError()), __FILE__, __LINE__));
		size_t pos = path.find_last_of("/");
		std::cout << path.substr(pos + 1, path.length() - pos - 5) << std::endl;
		fonts[path.substr(pos + 1, path.length() - pos - 5)] = font;
	}
}

TTF_Font	*FontManager::getFont(std::string ID) const
{
	auto it = fonts.find(ID);
	if (it != fonts.end())
		return (it->second);
	else
		return (NULL);
}

void	FontManager::clean(void)
{
	delete instance;
	instance = nullptr;
}