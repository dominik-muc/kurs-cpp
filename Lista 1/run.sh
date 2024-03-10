#Dominik Muc, 345952, Lista 1

echo "Podaj wejscie programu: "
if [ ! -f "main" ]; then 
    g++ main.cpp -o main
fi
read -r args
chmod +x main
echo "Wyjscie: "
./main $args