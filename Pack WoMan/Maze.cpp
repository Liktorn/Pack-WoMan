#include "Maze.h"
#include "Dot.h"


Maze::Maze(sf::Texture &texture)
	: m_mazeSize(0, 0)
	, m_texture(texture)
{
}


//Maze::~Maze()
//{
//}

void Maze::loadLevel(std::string name)
{
	sf::Image levelData;
	if (!levelData.loadFromFile("assets/levels/" + name + ".png"))
		throw std::runtime_error("Falied to load level (" + name + ")");

	m_mazeSize = sf::Vector2i(levelData.getSize());

	if(m_mazeSize.x < 15 || m_mazeSize.y < 15)
		throw std::runtime_error("The loaded level is to small (min 15 cells large)");

	for (unsigned int y = 0; y < m_mazeSize.y; y++)
	{
		for (unsigned int x = 0; x < m_mazeSize.x; x++)
		{
			sf::Color cellData = levelData.getPixel(x, y);

			if (cellData == sf::Color::Black)
				m_mazeData.push_back(Wall);
			else if (cellData == sf::Color::White)
				m_mazeData.push_back(Dot);
			else if (cellData == sf::Color::Green)
				m_mazeData.push_back(SuperDot);
			else if (cellData == sf::Color::Blue) 
			{
				//pacwoman position
				m_pacWomanPosition = sf::Vector2i(x, y);
				m_mazeData.push_back(Empty);
			}
			else if (cellData == sf::Color::Red) 
			{
				//ghost position
				m_ghostPositions.push_back(sf::Vector2i(x, y));
				m_mazeData.push_back(Empty);
			}
			else
				m_mazeData.push_back(Empty);
		}
	}
	m_renderTexture.create(32 * m_mazeSize.x, 32 * m_mazeSize.y);
	m_renderTexture.clear(sf::Color::Black);

	// draw someting...

	m_renderTexture.display();

	for (unsigned int i = 0; i < m_mazeData.size(); i++)
	{
		sf::Vector2i position = indexToPosition(i);

		if (m_mazeData[i] == Wall)
		{
			// temp wall
			sf::RectangleShape wall;
			wall.setSize(sf::Vector2f(32, 32));
			wall.setFillColor(sf::Color::Blue);
			wall.setPosition(32 * position.x, 32 * position.y);
			m_renderTexture.draw(wall);
		}
	}
}

void Maze::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sf::Sprite(m_renderTexture.getTexture()), states);

	static sf::CircleShape dot = getDot();
	static sf::CircleShape superDot = getSuperDot();

	for (unsigned int i = 0; i < m_mazeData.size(); i++)
	{
		sf::Vector2i position = indexToPosition(i);

		if (m_mazeData[i] == Dot)
		{
			dot.setPosition(32 * position.x + 16, 32 * position.y + 16);
			target.draw(dot, states);
		}
		else if(m_mazeData[i] == SuperDot)
		{
			superDot.setPosition(32 * position.x + 16, 32 * position.y + 16);
		}
	}
}

sf::Vector2i Maze::getPacWomanPosition() const
{
	return m_pacWomanPosition;
}
std::vector<sf::Vector2i> Maze::getGhostPositions() const
{
	return m_ghostPositions;
}

std::size_t Maze::positionToIndex(sf::Vector2i position) const
{
	return position.y * m_mazeSize.x + position.x;
}
sf::Vector2i Maze::indexToPosition(std::size_t index) const
{
	sf::Vector2i position;
	position.x = index % m_mazeSize.x;
	position.y = index / m_mazeSize.x;

	return position;
}
sf::Vector2i Maze::mapPixelToCell(sf::Vector2f pixel) const
{
	sf::Vector2i cell;
	cell.x = std::floor(pixel.x / 32.f);
	cell.y = std::floor(pixel.y / 32.f);
	return cell;
}
sf::Vector2f Maze::mapCellToPixel(sf::Vector2i cell) const
{
	sf::Vector2f pixel;
	pixel.x = cell.x * 32 + 16;
	pixel.y = cell.y * 32 + 16;
	return pixel;
}

bool Maze::isWall(sf::Vector2i position) const
{
	if (position.x < 0 || position.y < 0 || position.x >= m_mazeSize.x || position.y >= m_mazeSize.y)
		return false;
	return m_mazeData[positionToIndex(position)] == Wall;
}