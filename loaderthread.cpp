#include "loaderthread.h"

LoaderThread::LoaderThread(){}

LoaderThread::~LoaderThread(){}

MapaValorLetras::MapaValorLetras(){

    valorLetras['A'] = 0;
    valorLetras['B'] = 1;
    valorLetras['C'] = 3;
    valorLetras['D'] = 4;
    valorLetras['E'] = 5;
    valorLetras['F'] = 6;
    valorLetras['G'] = 7;
    valorLetras['H'] = 8;
    valorLetras['I'] = 9;
    valorLetras['J'] = 10;
    valorLetras['K'] = 11;
    valorLetras['L'] = 12;
    valorLetras['M'] = 13;
    valorLetras['N'] = 14;
    valorLetras['O'] = 15;
    valorLetras['P'] = 16;
    valorLetras['Q'] = 17;
    valorLetras['R'] = 18;
    valorLetras['S'] = 19;
    valorLetras['T'] = 20;
    valorLetras['U'] = 21;
    valorLetras['V'] = 22;
    valorLetras['W'] = 23;
    valorLetras['X'] = 24;
    valorLetras['Y'] = 25;
    valorLetras['Z'] = 26;
}

void LoaderThread::_init_(QMutex *_mutex, QMutex *_mutex2, QLabel *lbl){

    activo = true;
    pausado = false;
    error = false;
    mutexColaPedidos = _mutex;
    mutexColaPedidosP = _mutex2;
    listaClientes = new LSClientes();
    listaArticulos = new LDArticulos();
    colaPedidos = new ColaPedidos();
    colaPedidosPrioridad = new ColaPedidos();
    lblColaPedidos = lbl;
}

void LoaderThread::actualizarInventario(){

    NodoLDA *tmp = listaArticulos->ultimoNodo;
    QString strMsg = "";
    QByteArray msg;
    QFile archivo;

    //QString path = "C:/ITCR/Semestre I 2020/Estructuras de Datos/Proyectos/Proyecto 1/Armazon/Armazon/BD/Articulos.txt";
    QString path = "C:/Users/Fung Méndez/Desktop/Diego/Sem III/Estructuras/PROYECTS/Proyecto CONSOLE/Proyecto_1/BD/Articulos.txt";

    archivo.setFileName(path);

    while (tmp != nullptr){

        strMsg += tmp->strCodigo + "\t"
                + QString::number(tmp->cantidad) + "\t"
                + QString::number(tmp->tiempoFabricacion) + "\t"
                + tmp->strCategoria +"\t"
                + tmp->strUbicacion + "\n";
        tmp = tmp->anterior;
    }
    msg = strMsg.toUtf8();
    archivo.remove();
    archivo.open(QIODevice::ReadWrite | QIODevice::Text);
    archivo.write(msg);
    archivo.close();
}

QByteArray LoaderThread::leerArchivo(QString path){

    QByteArray contenido;
    QFile archivo;
    archivo.setFileName(path);
    if (!archivo.exists()){

        qDebug()<<"El archivo que desea abrir no existe\n";
    }

    archivo.open(QIODevice::ReadOnly | QIODevice::Text);

    if (!archivo.isOpen()){

        qDebug()<<"El archivo no se pudo abrir\n";
    }
    contenido = archivo.readAll();
    //qDebug()<<contenido<<"\n";
    //qDebug()<<contenido.length();
    archivo.close();
    return contenido;

}

void LoaderThread::cargarClientes(){

    QString strCodigo = "";
    QString strNombre = "";
    QString strPrioridad = "";

    //QString path = "C:\\ITCR\\Semestre I 2020\\Estructuras de Datos\\Proyectos\\Proyecto 1\\Armazon\\Armazon\\BD\\Clientes.txt";
    QString path = "C:\\Users\\Fung Méndez\\Desktop\\Diego\\Sem III\\Estructuras\\PROYECTS\\Proyecto CONSOLE\\Proyecto_1\\BD\\Clientes.txt";

    int codigo = 0;
    int prioridad = 0;
    int selector = 1; // Si es 1 dirige los datos a codigo, si es 2 a nombre y si es 3 a prioridad
    bool ok = true; // Esta bandera se usa en conjunto con el toInt() y permite saber si la conversion fue exitosa

    QByteArray texto = leerArchivo(path);
    texto = texto + "\n";
    //QByteArray texto = leerArchivo("El path de la PC  de Diego");

    for (int i = 0; i < texto.length(); ++i) {

        if(texto[i] == '\t'){
           // qDebug()<<"Cambiando el selector\n";
            selector++;
            continue;
        }
        else if(texto[i] == '\n'){
           // qDebug()<<"Creando nuevo cliente\n";

            if (strNombre == "" and strCodigo == "" and strPrioridad == "")
                continue;

            if (strNombre == "" or strCodigo == "" or strPrioridad == ""){

                qDebug()<<"Faltan datos en el archivo clientes\n";
                escribirArchivo(path, texto + "\nFaltan datos en el archivo clientes\n");
                error = true;
                break;

            }

            codigo = strCodigo.toInt(&ok);
            if (!ok){
                qDebug()<<"El codigo de cliente está incorrecto\n";
                escribirArchivo(path, texto + "\nEl codigo de cliente está incorrecto\n");
                error = true;
                break;
            }

            if (listaClientes->isInList(codigo)){

                qDebug()<<"El codigo de uno o varios clientes se encuentra repetido\n";
                escribirArchivo(path, texto + "\nEl codigo de uno o varios clientes se encuentra repetido\n");
                error = true;
                break;
            }


            prioridad = strPrioridad.toInt(&ok);
            if (!ok){
                qDebug()<<"La prioridad de cliente está incorrecta\n";
                escribirArchivo(path, texto + "\nLa prioridad de cliente está incorrecta\n");
                error = true;
                break;
            }

            if (prioridad < 1 or prioridad > 10){
                qDebug()<<"Se asigno una prioridad fuera de rango\n";
                escribirArchivo(path, texto + "\nSe asigno una prioridad fuera de rango\n");
                error = true;
                break;
            }
            listaClientes->insertarAlInicio(strNombre, codigo, prioridad);
            strNombre = strCodigo = strPrioridad = "";
            selector = 1;
            continue;
        }
        else if(texto[i] == '-')
            continue;

        //qDebug()<<"Vamos a guardar caracter\n";
        switch(selector){

        case 1: strCodigo += texto[i];break;
        case 2: strNombre += texto[i];break;
        case 3: strPrioridad += texto[i];break;

        default:qDebug()<<"No existe este codigo de selector";
            escribirArchivo(path, texto + "\nMas datos de los necesarios\n");
            error = true;
            break;
        }

    }
    if (error){
        qDebug()<<"ERROR: El archivo de clientes contenia un error, no se pudo ejecutar el programa\n";
    }
    else{
        listaClientes->imprimir();
        qDebug()<<"Se cargaron los clientes correctamente\n";
}

}

void LoaderThread::cargarArticulos(){

    QString strCodigo = "";
    QString strCategoria = "";
    QString strUbicacion = "";
    QString strCantidad = "";
    QString strTiempo = "";

    //QString path = "C:\\ITCR\\Semestre I 2020\\Estructuras de Datos\\Proyectos\\Proyecto 1\\Armazon\\Armazon\\BD\\Articulos.txt";
    QString path = "C:\\Users\\Fung Méndez\\Desktop\\Diego\\Sem III\\Estructuras\\PROYECTS\\Proyecto CONSOLE\\Proyecto_1\\BD\\Articulos.txt";

    Coordenadas* coordenadas;
    int cantidad = 0;
    int tiempoFabricacion = 0;
    int fila = 0;
    int columna = 0;
    int selector = 1; // Si es 1 dirige los datos a codigo, si es 2 a cantidad y si es 3 a tiempo y si es 4 a categoria y si es 5 a ubicacion
    bool ok = true; // Esta bandera se usa en conjunto con el toInt() y permite saber si la conversion fue exitosa

    QByteArray texto = leerArchivo(path);
    texto = texto +"\n";

    for (int i = 0; i < texto.length(); ++i) {
        if(texto[i] == '\t'){
            selector++;
            continue;
        }
        else if(texto[i] == '\n'){

            if (strCodigo == "" and strTiempo == "" and strCantidad == "" and strCategoria == "" and strUbicacion == "")
                continue;

            if (strCodigo == "" or strTiempo == "" or strCantidad == "" or strCategoria == "" or strUbicacion == ""){

                qDebug()<<"Hacen falta datos en el archivo\n";
                escribirArchivo(path, texto + "\nHacen falta datos en el archivo\n");
                error = true;
                break;
            }

            strCodigo = strCodigo.toUpper();
            strCategoria = strCategoria.toUpper();

            if (listaArticulos->isInList(strCodigo)){

                qDebug()<<"El codigo de uno o varios articulos se encuentra repetido\n";
                escribirArchivo(path, texto + "\nEl codigo de uno o varios articulos se encuentra repetido\n");
                error = true;
                break;
            }

            cantidad = strCantidad.toInt(&ok);
            if (!ok){
                qDebug()<<"La cantidad del articulo está incorrecto\n";
                escribirArchivo(path, texto + "\nLa cantidad del articulo está incorrecto\n");
                error = true;
                break;
            }

            if (cantidad < 0){
                qDebug()<<"Se asigno una cantidad negativa\n";
                escribirArchivo(path, texto + "\nSe asigno una cantidad negativa\n");
                error = true;
                break;
            }

            tiempoFabricacion = strTiempo.toInt(&ok);
            if (!ok){
                qDebug()<<"El tiempo de fabricacion del articulo está incorrecto\n";
                escribirArchivo(path, texto + "\nEl tiempo de fabricacion del articulo está incorrecto\n");
                error = true;
                break;
            }

            if (tiempoFabricacion < 0){
                qDebug()<<"Se asigno un tiempo de fabricacion negativo\n";
                escribirArchivo(path, texto + "\nSe asigno un tiempo de fabricacion negativo\n");
                error = true;
                break;
            }

            if (strCategoria != "A" and strCategoria != "B" and strCategoria != "C"){

                qDebug()<<"Se asigno una categoria inexistente\n";
                escribirArchivo(path, texto + "\nSe asigno una categoria inexistente\n");
                error = true;
                break;
            }

            coordenadas = convertirUbicacion(strUbicacion);
            if (coordenadas->fila == -1 or coordenadas->columna == -1){

                qDebug()<<"La posicion del articulo no existe en la bodega\n";
                escribirArchivo(path, texto + "\nLa posicion del articulo no existe en la bodega\n");
                error = true;
                break;
            }
            fila = coordenadas->fila;
            columna = coordenadas->columna;
            if (fila > 10 or fila < 1){

                qDebug()<<"La ubicacion del articulo excede el limite\n";
                escribirArchivo(path, texto + "\nLa ubicacion del articulo excede el limite\n");
                error = true;
                break;
            }

            listaArticulos->insertarAlInicio(strCodigo, strUbicacion, strCategoria, tiempoFabricacion, cantidad, fila, columna);
            strUbicacion = "";
            strCodigo = "";
            strCategoria = "";
            strCantidad = "";
            strTiempo = "";
            tiempoFabricacion = 0;
            cantidad = 0;
            fila = 0;
            columna = 0;
            selector = 1;
            continue;
        }
        else if(texto[i] == '-')
            continue;

        //qDebug()<<"Vamos a guardar caracter\n";
        switch(selector){

        case 1: strCodigo += texto[i];break;
        case 2: strCantidad += texto[i];break;
        case 3: strTiempo += texto[i];break;
        case 4: strCategoria += texto[i];break;
        case 5: strUbicacion += texto[i];break;

        default:qDebug()<<"No existe este codigo de selector\nHay mas datos de los necesarios\n";
            escribirArchivo(path, texto + "\nHay mas datos de los necesarios\n");
            error = true;
            break;
        }

    }
    if (error){
        qDebug()<<"ERROR: El archivo de articulos contenia un error, no se pudo ejecutar el programa\n";
    }
    else
        qDebug()<<"Se cargaron los articulos correctamente\n";


}

Coordenadas* LoaderThread::convertirUbicacion(QString ubicacion){

    QChar strColumna = ' ';
    QString strFila = "";
    MapaValorLetras* alfabeto = new MapaValorLetras();
    Coordenadas* coordenadas = new Coordenadas();

    if (ubicacion.length() == 3){

        if (ubicacion[0].isLetter()){
            strColumna = ubicacion[0].toUpper();

            coordenadas->columna = alfabeto->valorLetras.value(strColumna);
        }
        else{
            coordenadas->columna = -1;
        }
        if (ubicacion[1].isNumber() and ubicacion[2].isNumber()){
            strFila += ubicacion[1];
            strFila += ubicacion[2];
            coordenadas->fila = strFila.toInt();
        }
        else{
            coordenadas->fila = -1;
        }
    }
    else{
        coordenadas->fila = -1;
        coordenadas->columna = -1;

    }
    return coordenadas;
 }

QString LoaderThread::renombrarArchivo(QString path){

    QFile archivo;
    QDateTime date;
    QString strNuevoNombre = "";
    date = QDateTime::currentDateTime();
    strNuevoNombre = path + date.toString("dd-MM-yyyy hh-mm-ss") + ".txt";
    archivo.setFileName(path);
    archivo.rename(strNuevoNombre);

    return strNuevoNombre;
}

void LoaderThread::copiarArchivo(QString path, QString newPath){

    QFile archivo;
    archivo.setFileName(path);
    archivo.copy(path, newPath);
}

void LoaderThread::escribirArchivo(QString path, QByteArray msg){

    QFile archivo;
    archivo.setFileName(path);
    if (!archivo.exists()){

        qDebug()<<"El archivo que desea abrir no existe\n";
    }

    archivo.open(QIODevice::WriteOnly | QIODevice::Text);

    if (!archivo.isOpen()){

        qDebug()<<"El archivo no se pudo abrir\n";
    }
    archivo.write(msg);
    archivo.close();

}

void LoaderThread::borrarArchivo(QString path){

    QFile archivo;
    archivo.remove(path);
}

void LoaderThread::cargarPedido(){

    QString strNumeroPedido = "";
    QString strCodigoCliente = "";
    QString strCodigoArticulo = "";
    QString strCantidad = "";
    Pedido *pedido;
    QString strNombreArchivo = "";

    //QString pathSinProcesar = "C:\\ITCR\\Semestre I 2020\\Estructuras de Datos\\Proyectos\\Proyecto 1\\Armazon\\Armazon\\BD\\Pedidos\\Sin procesar";
    //QString pathError = "C:\\ITCR\\Semestre I 2020\\Estructuras de Datos\\Proyectos\\Proyecto 1\\Armazon\\Armazon\\BD\\Pedidos\\Error";
    //QString pathProcesado = "C:\\ITCR\\Semestre I 2020\\Estructuras de Datos\\Proyectos\\Proyecto 1\\Armazon\\Armazon\\BD\\Pedidos\\Procesados";

    QString pathSinProcesar = "C:\\Users\\Fung Méndez\\Desktop\\Diego\\Sem III\\Estructuras\\PROYECTS\\Proyecto CONSOLE\\Proyecto_1\\BD\\Pedidos\\Sin procesar";
    QString pathError = "C:\\Users\\Fung Méndez\\Desktop\\Diego\\Sem III\\Estructuras\\PROYECTS\\Proyecto CONSOLE\\Proyecto_1\\BD\\Pedidos\\Error";
    QString pathProcesado = "C:\\Users\\Fung Méndez\\Desktop\\Diego\\Sem III\\Estructuras\\PROYECTS\\Proyecto CONSOLE\\Proyecto_1\\BD\\Pedidos\\Procesados";

    QDir dirSinProcesar;

    int numeroPedido = 0;
    int codigoCliente = 0;
    int cantidad = 0;
    int selector = 1; // Si es 1 dirige los datos a numeroPedido, si es 2 a codigoCliente y si es 3 a CodigoArticulo, si es 4 a cantidad
    bool ok = true; // Esta bandera se usa en conjunto con el toInt() y permite saber si la conversion fue exitosa
    dirSinProcesar.setPath(pathSinProcesar);

    if (dirSinProcesar.count() > 2){

        QByteArray texto = leerArchivo(pathSinProcesar + "\\" + dirSinProcesar[2]);
        texto = texto + "\n";

        int i = 0;
        for (i; i < texto.length(); ++i) {

            if (texto[i] == '\n'){

                if (strCodigoCliente != ""){
                    numeroPedido = strNumeroPedido.toInt(&ok);
                    if (!ok){
                        qDebug()<<"El numero de pedido es incorrecto\n";
                        escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nEl numero de pedido es incorrecto\n");
                        break;
                    }
                    codigoCliente = strCodigoCliente.toInt(&ok);
                    if (!ok){
                        qDebug()<<"El codigo de cliente es incorrecto\n";
                        escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nEl codigo de cliente es incorrecto\n");
                        break;
                    }

                    if (!listaClientes->find(codigoCliente)){
                        qDebug()<<"El codigo de cliente no existe\n";
                        escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nEl codigo de cliente no existe\n");
                         ok = false;
                    }

                    qDebug()<<"Al final me quedo esto en las variables: " + strNumeroPedido + "/" + strCodigoCliente;
                    i++;
                    selector = 3;
                    break;
                }
                selector++;
                continue;

            }
            switch(selector){
            case 1: strNumeroPedido += texto[i];break;
            case 2: strCodigoCliente += texto[i];break;
            default:qDebug()<<"No existe este codigo de selector";
                escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nRevise que el archivo no tenga mas/menos datos de los necesarios\n");
                 ok = false;

            }

        }

        if (strCodigoCliente == "" or strNumeroPedido == ""){

            qDebug()<<"No se cargo correctamente el codigo de articulo o codigo de cliente\n";
            escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nHay un error con el codigo de cliente o el codigo de articulo\n");

            ok = false;
        }

        if (!ok){
            i += texto.length(); //Para que no entre al for
        }
        else{
            if(!numeroPedidos.contains(numeroPedido)){

                pedido = new Pedido();
                qDebug()<<"NUMERO DE PEDIDO"<<numeroPedido<<Qt::endl;
                pedido->numeroPedido = numeroPedido;
                pedido->codigoCliente = codigoCliente;
                pedido->infoFactura->numeroPedido = QString::number(numeroPedido);
                pedido->infoFactura->codigoCliente = QString::number(codigoCliente);


            }
            else{
                qDebug()<<"El numero de pedido ya existe\n";
                escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nEl numero de pedido ya existe\n");
                ok = false;
                i += texto.length();
            }
        }
        for (i; i < texto.length(); ++i) {
            if(texto[i] == '\t'){
                selector++;
                continue;
            }
            else if(texto[i] == '\n'){

                if (strCodigoArticulo == "" and strCantidad == "")
                    continue;

                if (strCodigoArticulo == "" or strCantidad == ""){

                    qDebug()<<"Faltan datos del pedido\n";
                    escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nFaltan datos del pedido\n");
                    ok = false;
                    break;
                }

                strCodigoArticulo = strCodigoArticulo.toUpper();
                if (!listaArticulos->isInList(strCodigoArticulo)){
                    qDebug()<<"El codigo de articulo no existe\n";
                    escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nEl codigo de articulo no existe\n");
                    ok = false;
                    break;
                }

                cantidad = strCantidad.toInt(&ok);
                if (!ok){
                    escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nLa cantidad de articulo está incorrecta\n");
                    qDebug()<<"La cantidad de articulo está incorrecta\n";
                    break;
                }

                if (cantidad < 0){
                    qDebug()<<"Se asigno una cantidad fuera de rango\n";
                    escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nSe asigno una cantidad fuera de rango\n");
                    ok = false;
                    break;
                }
                if (!pedido->listaPedido->isInList(strCodigoArticulo)){
                    pedido->listaPedido->insertarAlInicio(strCodigoArticulo, cantidad, listaArticulos->getUbicacion(strCodigoArticulo));

                    strCodigoArticulo = strCantidad = "";
                    selector = 3;
                    cantidad = 0;
                    continue;
                }
                else{

                    qDebug()<<"Hay articulos repetidos en el pedido\n";
                    escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nHay articulos repetidos en el pedido\n");
                    ok = false;
                    break;
                }
            }
            else if(texto[i] == '-')
                continue;

            switch(selector){
            case 3: strCodigoArticulo += texto[i];break;
            case 4: strCantidad += texto[i];break;
            default:qDebug()<<"No existe este codigo de selector pedido";
                escribirArchivo(pathSinProcesar + "\\" + dirSinProcesar[2], texto + "\nRevise que el archivo no tenga mas/menos datos de los necesarios\n");
                ok = false;
            }

        }
        strNombreArchivo = pathSinProcesar + "\\" + dirSinProcesar[2];

        //dirSinProcesar.setPath("C:\\ITCR\\Semestre I 2020\\Estructuras de Datos\\Proyectos\\Proyecto 1\\Armazon\\Armazon\\BD\\Pedidos\\Sin procesar");
        dirSinProcesar.setPath("C:\\Users\\Fung Méndez\\Desktop\\Diego\\Sem III\\Estructuras\\PROYECTS\\Proyecto CONSOLE\\Proyecto_1\\BD\\Pedidos\\Sin procesar");

        strNombreArchivo = renombrarArchivo(strNombreArchivo);

        if (!ok){
            qDebug()<<"ERROR: Se movio el archivo a carpeta de errores\n";
            copiarArchivo(strNombreArchivo, pathError + "\\" + dirSinProcesar[2]);
            borrarArchivo(strNombreArchivo);

        }


        else{
            //qDebug()<<"Prueba para ver que falla\n";
            //qDebug()<<"Codigo cliente pedido "<<pedido->codigoCliente<<endl;
            //qDebug()<<"Find "<<listaClientes->find(pedido->codigoCliente)<<endl;
            //int priori = (listaClientes->find(pedido->codigoCliente))->prioridad;
            //qDebug()<<"Prioridad "<<priori<<endl;
           if ((listaClientes->find(pedido->codigoCliente))->prioridad == 10){
                //qDebug()<<"No se cae aqui";             
                    colaPedidosPrioridad->encolar(pedido);
                    numeroPedidos << numeroPedido;
                    QDateTime date;
                    date = QDateTime::currentDateTime();
                    QString strFechaHora = date.toString("dd-MM-yyyy hh:mm:ss");
                    pedido->infoFactura->horaLoader = strFechaHora;
                    qDebug()<<"PPPPPPPPPPPPPPRIORIDAD\n";
                    colaPedidosPrioridad->imprimir();
                    colaPedidosPrioridad->pedidosTotales += 1;
                    colaPedidosPrioridad->pedidosActuales += 1;
                    int pedidosActuales = colaPedidosPrioridad->pedidosActuales + colaPedidos->pedidosActuales;
                    int pedidosTotales = colaPedidosPrioridad->pedidosTotales + colaPedidos->pedidosTotales;
                    lblColaPedidos->setText(QString::number(pedidosActuales) + " / " + QString::number(pedidosTotales));
                    copiarArchivo(strNombreArchivo, pathProcesado + "\\" + dirSinProcesar[2]);
                    borrarArchivo(strNombreArchivo);


           }
           else{

                    colaPedidos->encolar(pedido);
                    numeroPedidos << numeroPedido;
                    QDateTime date;
                    date = QDateTime::currentDateTime();
                    QString strFechaHora = date.toString("dd-MM-yyyy hh:mm:ss");
                    pedido->infoFactura->horaLoader = strFechaHora;
                    qDebug()<<"NNNNNNNNNNNORMAL\n";
                    colaPedidos->imprimir();
                    colaPedidos->pedidosTotales += 1;
                    colaPedidos->pedidosActuales += 1;
                    int pedidosActuales = colaPedidosPrioridad->pedidosActuales + colaPedidos->pedidosActuales;
                    int pedidosTotales = colaPedidosPrioridad->pedidosTotales + colaPedidos->pedidosTotales;
                    lblColaPedidos->setText(QString::number(pedidosActuales) + " / " + QString::number(pedidosTotales));
                    copiarArchivo(strNombreArchivo, pathProcesado + "\\" + dirSinProcesar[2]);
                    borrarArchivo(strNombreArchivo);


            }
        }
    }

    //else
      // qDebug()<<"No hay archivos\n";
}

void LoaderThread::run(){

    while(activo){
        if(mutexColaPedidos->tryLock() and mutexColaPedidosP->tryLock()){
        cargarPedido();
        mutexColaPedidos->unlock();
        mutexColaPedidosP->unlock();
        }

        sleep(1);

        while(pausado)
            sleep(1);
    }
}

void LoaderThread::pausar(){

    pausado = true;
}

void LoaderThread::reanudar(){

    pausado = false;
}
