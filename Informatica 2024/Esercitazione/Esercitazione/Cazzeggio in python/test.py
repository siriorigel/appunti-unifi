import turtle

def draw_axes():
    # Disegna l'asse x
    turtle.penup()
    turtle.goto(-200, 0)
    turtle.pendown()
    turtle.forward(400)
    turtle.write("X")

    # Disegna l'asse y
    turtle.penup()
    turtle.goto(0, -200)
    turtle.left(90)
    turtle.pendown()
    turtle.forward(400)
    turtle.write("Y")

    turtle.right(90)

def plot_data(data):
    turtle.penup()
    turtle.goto(-180, data[0])
    turtle.pendown()
    for i in range(len(data) - 1):
        turtle.goto(-180 + 40 * (i + 1), data[i + 1])

def main():
    
    # Input dei dati
    data = []
    print("Inserisci 10 dati:")
    for i in range(10):
        data.append(int(input("Dato {}: ".format(i + 1))))

    # Inizializza la finestra di disegno
    turtle.setup(width=800, height=600)
    turtle.speed(1)
    turtle.showturtle()
    turtle.shape("turtle")

    # Disegna gli assi
    draw_axes()

    # Disegna il grafico
    plot_data(data)

    # Chiudi la finestra alla pressione del mouse
    turtle.exitonclick()

if __name__ == "__main__":
    main()
