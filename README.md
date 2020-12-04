# Captura de Paquetes en una Interfaz de Red
Es un proyecto de la universidad con el uso del programa **wireshark** y el **lenguaje C**
con el fin de analizar paquetes de red en una interfaz de red de cualquier equipo. Sea un
Ordenador o servidor de Linux

**En este proyecto se debe tener instalado wireshark para cumplir su objetivo**.
El codigo fue creado en Linux. Por lo que para instalar Wireshark en linux se debe usar
este comando:

**Debian o Ubuntu, o derivados** - `apt-get install wireshark`

**Centos** - `yum install wireshark`


**Nota:** Para ello el equipo debe tener permiso para sálida a internet y debe tener configurado
un repositorio público.



Primero debemos saber cual es nuestra interfaz de red, para descubrirla utilizamos el
siguiente comando:
`tshark -i ens18 -a duration:10 > datos_trafico.txt`
generando un archivo llamado datos_traficos.txt en donde se almacenara toda la informacion


Para este archivo se debe crear un TDA lista, con sus operaciones, donde cada linea del
archivo en un elemento del TDA, la intención es extarer en un arreglo la siguiente info:

**Tiempo de muestra:**
25 **5.757848883** JuniperN_a9:b0:11 -> Spanning-tree-(for-bridges)_00 STP 60 RST. Root =
32768/0/84:18:88:a9:86:01 Cost = 0 Port = 0x828f

**Protocolo de red:**
25 **5.757848883** JuniperN_a9:b0:11 -> Spanning-tree-(for-bridges)_00 STP 60 RST. Root =
32768/0/84:18:88:a9:86:01 Cost = 0 Port = 0x828f
Con el objetivo de observar cuales son los paquetes que interactuan en este equipo.
