#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
    string email;
    string phone;
    string username;
    string password;
    bool logged = false;

public:
    User(string user_email, string user_phone, string user_username, string user_password)
        : email(user_email), phone(user_phone), username(user_username), password(user_password) {}

    void login(string entered_username, string entered_password)
    {
        if (entered_username == username && entered_password == password)
        {
            logged = true;
            cout << "¡Bienvenido, " << username << "!" << endl;
        }
        else
        {
            cout << "Error al iniciar sesión. Verifica tu nombre de usuario y contraseña." << endl;
        }
    }

    void logout()
    {
        logged = false;
        cout << "¡Adiós, " << username << "!" << endl;
    }

    void changePswrd(string old_password, string new_password)
    {
        if (logged && old_password == password)
        {
            password = new_password;
            cout << "Contraseña actualizada con éxito." << endl;
        }
        else
        {
            cout << "Error al actualizar la contraseña. Verifica tu contraseña actual." << endl;
        }
    }
};

class Customer : public User
{
public:
    Customer(string user_email, string user_phone, string user_username, string user_password)
        : User(user_email, user_phone, user_username, user_password) {}

    float buyProd(string prod_name, float prod_price, float &user_bucks)
    {
        if (logged)
        {
            if (user_bucks >= prod_price)
            {
                cout << "El cliente " << username << " compró " << prod_name << " por $" << prod_price << endl;
                user_bucks -= prod_price;
                return user_bucks;
            }
            else
            {
                cout << "No tienes suficiente dinero para comprar " << prod_name << "." << endl;
                return user_bucks;
            }
        }
        else
        {
            cout << "Error: No se ha iniciado sesión." << endl;
            return user_bucks;
        }
    }

    void reportSeller(string seller_name, string problem_descrip)
    {
        if (logged)
        {
            cout << "El cliente " << username << " reportó al vendedor " << seller_name << " por '" << problem_descrip << "'" << endl;
        }
        else
        {
            cout << "Error: No se ha iniciado sesión." << endl;
        }
    }
};

class Seller : public User
{
public:
    Seller(string user_email, string user_phone, string user_username, string user_password)
        : User(user_email, user_phone, user_username, user_password) {}

    void chambear(int checkin_time, int work_time)
    {
        if (logged)
        {
            cout << "El vendedor " << username << " comenzó a trabajar a las " << checkin_time << ", su salida es a las " << checkin_time + work_time << " horas" << endl;
        }
        else
        {
            cout << "Error: No se ha iniciado sesión." << endl;
        }
    }

    void attackCustomer(string customer_name, string problem_descrip)
    {
        if (logged)
        {
            cout << "El vendedor " << username << " atacó al cliente " << customer_name << " por '" << problem_descrip << "'" << endl;
        }
        else
        {
            cout << "Error: No se ha iniciado sesión." << endl;
        }
    }
};

int main()
{
    Customer itsMe = Customer("a23310151@ceti.mx", "3322749457", "Yashiro", "12345");

    // Intento de iniciar sesión
    itsMe.login("Yashiro", "12345");

    // Cambio de contraseña
    itsMe.changePswrd("12345", "HolaMundo");

    // Compra de producto
    float user_money = 50020.0;
    user_money = itsMe.buyProd("Jordans Chicago Lost Found", 50000.99, user_money);
    cout << "Esa compra me dejó solo con " << user_money << " pejecoins X_X" << endl;

    // Reportar vendedor
    itsMe.reportSeller("Gobierno", "Mal servicio");

    // Cierre de sesión
    itsMe.logout();

    // Crear un vendedor
    Seller AMLO = Seller("cuatrote@mx.com", "1234567890", "Gobierno", "arribalaschivas");

    // Intento de iniciar sesión como vendedor
    AMLO.login("Gobierno", "arribalaschivas");

    // Hacer trabajo como vendedor
    AMLO.chambear(9, 8);

    // Atacar a un cliente como vendedor
    AMLO.attackCustomer("Yashiro", "Cliente revelandose ante el sistema");

    // Cerrar sesión como vendedor
    AMLO.logout();

    return 0;
}
