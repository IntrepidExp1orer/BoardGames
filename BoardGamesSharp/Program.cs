using BoardGamesSharp.Core;

class Program
{
    static void Main(string[] args)
    {
        GameManager manager = new GameManager();

        // Сначала добавляем игроков
        manager.AddPlayers();

        // Затем запускаем цикл выбора игры
        manager.Run();
    }
}




