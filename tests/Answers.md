# 2018-01-07

#### Quali sono le 'generazioni' della storia dei calcolatori?

```
1642-1834 Dispositivi meccanici (Babbage-Pascal) in grado di eseguire operazioni aritmetiche.
 
1936-1953 Primi calcolatori, Colossus primo calcolatore elettronico, IAS(Von neumann) Calcolatore con la stessa architettura dei pc moderni

1960-1965 Primi calcolatori progettati per calcolo scientifico e alto livello

1970-1990 primi calcolatori per general purpose 
```

#### Descrivere le caratteristiche delle segueneti tipologie di memoria: PROM, EPROM, EEPROM.

```
PROM: (Programmable ROM) questa memoria può essere scritta una sola volta ma la differenza è che i metodi con cui è scritta sono più semplici e meno dispendionsi. 
EPROM (Erasable PROM) funziona come una PROM ma può essere riscritta usando il laser
EEPROM (Elettracly EPROM), ciascuna delle celle di memoria capace di memorizzare un singolo bit è costituito da due transistor MOS, uno di memoria e uno di accesso. 
La riprogrammazione può essere fatta incircuit e può essere cancellata elettricamente più velocemente della EPROM
```

#### Descrivere brevemente la codifica digitale di un suono

```
Il suono dal punto di vista fisico è un alterazione della pressione dell'aria. Esso è rappresentato fisicamente come un'onda,
quindi il tracciato dei solchi del vinile e l'intensità del campo magnetico sul nastro seguono l'andamento della curva dell'ampiezza
--> ma questa è un rappresentazione analogica.
Per poterlo rappresentare digitalmente si assegnano dei numeri che rappresentano di volta in volta il vallore dell'ampiezza in istanti successivi di tempo,
la successione di questi numeri rappresenta l'andamento della curva di ampiezza,
fornisce una descrizione discreta dell'onda sonora.
Bisogna effettuare dei campionamenti dell'onda sonora, quindi se la frequenza di campionamento di un'onda sonora è elevata -->
il suono avrà una qualità migliore.
```

#### Che cosa si intende per MIPS e MFLOPS 

```
MIPS (Million Instructions Per Second), è un unita di misura della frequenza di istruzioni effettuata da un microprocesso,
le istruzioni sono tutte di tipo intero e non usano tutti i set di istruzioni della cpu)
MIPS = frequenza / 10^6 * CPI (clock per instruction --> quanti clock servono per effettuare un istruzione).

MFLOPS è il corrispondente unità di misura in cui però non ci sono operazioni intere ma in float 
```

#### Quali sono le principale interfacce per dischi magnetici?

```
1) interfaccia IDE-ATA è formata da un cavo piatto che è usato per connetere il disco rigido alla scheda madre
2) interfaccia serial ata trasmette i dati in modo seriale , e quindi invece di utilizzare molteplici fili per trasmettere i dati ne utilizza solo due, uno per trasmettere i dati e uno per ricevere. Ci sono poi è anche fili per i segnali di controllo
3) SCSI o SAS (Serial attached SCSI) che in ambito enterprise permette una maggiore affidabilità
```

#### Descrivere come può essere realizzato il trasferimento di un blocco di memoria tra due perifiche senza la partecipazione della CPU 

```
Può avvenire attraverso l'utilizzo del DMA, una chip composto da 4 registri che è in grado di trasferire dati da una periferica all'altra senza l'intervento della CPU.
Nei registri vengono memorizzate le varie informazioni, come la grandezza del dato, l'indirizzo di arrivo ecc. La CPU assegna al DMA questo “compito” e al termine viene avvertita con un interrupt.
```

# 2018-02-14

#### Descrivere l'evoluzione delle istruzioni SIMD nell'ambito delle architetture x86

```
1) MMX utilizza 8 registri a 64 bit (che condivide con la FPU ma che non possono essere utilizzati contemporaneamente ad essa) Registri : MM0-MM7
2) XMM utilizza 8 nuovi registri 64 bit in cui è possibile usare unità floating point
3) AVX nuovi registri da 256 bit in cui ci sono istruzioni a tre operandi ed utilizza più velocemente le istruzioni floating point
```

#### Elencare i tipi di memoria e per ciascuno indicare l'utilizzo tipico

```
Register (fast,expensive)
Cache   (bit slower,very expensive)
RAM (slower than cache, faster than SSD)
SSD (slower than everything else,cheaper)
Tape backup (slow,affordable)
```

#### Quali sono le tre principale tecniche di rappresenzatione di numeri intero con segno? Dare descrizione

```
1) Complemento a due, per rappresentare i numeri interi negativi si invertono i bit e si aggiunge 1
2) Con segno, il bit più a sinitra indica il segno (1 negativo)
3) Eccesso 2^m-1: rappresenta i numeri come somma di se stessi + 2^m-1 
```

#### In quale periodo storico furono realizati i primi calcolatori meccanici? 

```
I primi calcolatori meccanici sono stati realizzati da Pascal in cui erano possibili operazioni aritmetiche di somma e sottrazione.
Da Leibniz in cui nel suo calcolatore si poteva fare anche moltiplicazione e divisione.
Babbage in cui tentò di costruire il primo dispositivo programmabile
```

#### Quanti flip-flop sono necessari per realizzare una SRAM 32K x 8?

```
32k x 8 = 256000 perchè ci sono 32000 parole,ognuna rappresentata da 8 flip flop.
```

#### Che cosa si intende per "esecuzione fuori ordine delle istruzioni/micro-istruzioni" e in quali casi può essere utile?

```
L' esecuzione fuori ordine consiste nel scavalcare un'operazione e passare a quelle successive facendo in modo che i risultati finali siano gli stessi.
Viene quindi applicata quando per esempio un'istruzione per essere eseguita deve aspettare che ne venga eseguita un'altra, la CPU così invece di aspettare esegue alcune operazioni successive.
```

# 2018-06-21

#### In una moderna CPU multi-core come sono generalmente organizzati i tre livelli di cache?

```
L1 (64KB) per ogni core
L2 (1MB) per ogni core
L3 (1.375MB per core)
I primi due livelli sono di cache sono disponibili per ogni core, mentre il terzo è condiviso con tutti i core.
Skylake-x
```

#### Descrivere il tipo di interfacciamento/BUS che utilizzano le schede grafiche odierne evidenziando come sia possibile raggiungere elevate ampiezze di banda

```
Le gpu odierne utilizzano il PCI express che ha sostituito l'AGP. Inoltre ci sono tecnologie SLI(Nvidia) e CrossFireX (AMD/ATI) che consentono di collegare più shcede grafiche contemporaneamente.

Attualmente si possono utilizzare contemporaneamente anche 1PCIE x 16 linee in modo da aumentare l'ampiezza di banda
```

#### Che cos'è la codifica dei caratteri UNICODE e per quale motivo è stata introdotta?

```
Unicode è stato introdotto per supportare tutti i tipi di caratteri esistenti (sopratutto delle lingue orientali, dei simboli matematica, etc..) , esistono tre tipi di unicode, UTF-8 (8 bit),UTF-16,UTF-32
```

#### Quali sono le principali differenze fra un compilatore e un interprete? perchè un programma compilato è in genere più veloce di uno interpretato?

```
un compilatore prende un codice sorgente e lo trasforma in linguaggio macchina, quindi poi quando viene eseguito è gia compilato per quell'architettura ed è più veloce.
Usando un interprete invece a runtime il codice viene tradotto in linguaggio macchina e quindi è più lento.
In entrambe le tecniche (c --> compilato) , (python--> interpretato) sono disponibili solitamente delle tecniche per ottimizzare il codice sia a livello di compilazione che di interpretazione ,
tuttavia il codice interpretato rimane più lento di un codice compilato ottimizzato per quella architettura.
```

#### Che cos'è il processo di fotolitografia utilizzato nella fabbricazione dei circuiti integrati?

```
è un processo usato per riprodurre su substrati le goeemtrie rappresentate su maschere. Tale riproduzione è effettuata sovrapponendo una sottile lamina di gelatine fotosensibile al substrato stesso e procedendo all'illuminazione.
```

#### Definire le modalità big endian e little endian e mostrare come la DWORD (A00BB75h) viene memorizzata.

```
big endian (A00BB75F)       1024    |   A0  |
                            1025    |   0B  |
                            1026    |   B7  |
                            1027    |   5F  |


little endian               1024    |   5F  |
                            1025    |   B7  |
                            1026    |   0B  |   
                            1027    |   A0  |    
```

#### Disegnare circuito di un comparatore di parole a 4 bit

```
nell'altra slide lol
```

#### Quali sono le principali caratteristiche delle CPU ARM utilizzate nei sistemi embedded rispetto alle CPU utilizzate nei PC?

```
Le cpu arm classic sono ARM7-9-11. <
Le cpu arm embedded sono Cortex-M0-1-3-4-x < 
Le cpu arm application sono Cortex-A5-7-8-9-15.

Una cpu cortex-A8 ha versioni siia a 32 che 64 bit e possono includere istruzioni SIMD e floating point.
Si utilizzano per il risparmio sia in temrine di soldi che in termine di energia ,
sono utilizzate molto spesso in dispositivi mobili o IoT (raspberry, bananpi, etc)
```

#### Cosa si intende per dischi in configurazione RAID?

```
RAID è una configurazione lato software o hardware che permette di utilizzare più dischi in parallelo e eseguire operazioni di mirroring,backup,e ingrandimento di un volume.
```

#### Descrivere i casi in cui il risultato di un'operazione in aritmetica finita non appartiene all'insieme dei valori rappresentabili e fare alcuni esempi.

```
L’overflow si verifica se il riporto generato nel sommare i bit di segno
è diverso dal riporto utilizzato per sommare i bit di segno (normalmente l’overflow viene indicato da un particolare bit di overflow del sommatore).
Underflow quando il risultato è troppo piccolo in valore assoluto nell'insieme dei valori e non è rappresentabile
NON appartanenza all'inseme quando il risultato non appartiene all'insieme dei valori rappresentabili.
ES: numeri a precisione finita con 3 cifre senza virgola e senOVERFLOW: 600 + 600 = 1200
UNDERFLOW : 300 – 600 = -300
NON APPARTENENZA ALL'INSIEME: 007 / 002 = 3,5
```

#### Quali sono le principali differenza fra un compilatore e un assemblatore?

```
Il compilatore traduce un linguaggio di alto livello (C) in linguaggio macchina.
L'assemblatore invece trasforma le istruzioni nel corrispondente linguaggio macchine (op-code).
Un compilatore può essere per esempio GCC, mentre un assembler è per esempio NASM.
Entrambi necessitano poi di un linker (nella maggior parte dei casi) per linkare i file oggetto e inserire l'"indirizzo" delle varie librere condivise (Linux).

Messo tra virgolette perchè in verità nell'ELF si usa la PLT e GOT per determinare l'indirizzo delle varie funzioni.
```

#### Quali sono le principali differenze in termini di prestazioni tra dischi magnetici e dischi allo stato solido?

```
gli SSD sono basati su memorie flash NAND.
Il tempo di seek è ridtto, ed è più di 50 volte più veloce rispetto a un HD.
Il tempo di trasferimento bassa da 100=300MB fino anche a 6GB/sec
Si ha una maggiore durata e meno rumori.
```

# 2018-09-07

#### Descrivere brevemente la codifica digitale di un'immagine a livelli di grigio.

```
L'immagine è rappresentata tramite una griglia/matrice di pixel di ognuno dei quali è memorizzata l'intensità luminosa o colore.
in scala di grigio un pixel viene codificato con un byte-->256 livelli

Livello 0 --> Nero
Livello 255 --> Bianco

a colori invece un pixel viene codificato con tre byte (R,G,B),Ciascuno dei quali rappresenta l'intensità dei uno dei tre colori fondamentali
```

#### Una CPU moderna (es.Intel Core I7) che ordine di grandezza (GigaFlops) raggiunbge in termini di prestazioni?

```
Skylake-X raggiunge 977 Gigaflops
```

#### Elencare i tipi di Ram e per ciascuno indicare l'utilizzo tipico

```
SRAM --> circuiti FLIP-FLOP tipo D, molto veloci ma costosi --> cache
DRAM (Dynamic Ram) --> array di celle ognuna costituita da un transitor più un condensatore , economiche --> RAM
```

#### Quali sono le principali tipologie di architetture parallele?

```
Thread --> nel chip
coprocessori
multi-processori --> con shared memory
multi-computer --> ogni cpu con private memory 
cluster in internet --> Computer collegati tramite internet
```

#### Descrivere cos'è il fetch delle istruzioni

```
con il PC (program counter) si "fetcha" l'istruzione puntata con il PC.
L'IR la esegue e il PC punta a quella dopo.
Esempio all'indirizzo 0x400a9c è presenta l'istruzione `c3`, --> `c3` = ret in asm
```

# 2018-09-14

#### Definire le architetture superscalari e indicarne i principali vantaggi.

```
Le architetture superscalari supportano il calcolo parallelo su un singolo chip, ovvero sono presenti più unità funzionali dello stesso tipo,per esempio solitamente sono presenti più ALU, ma anche unità floating point ecc.
In questo modo si possono eseguire in un singolo ciclo più operazioni.
```

#### Quante linee di uscita ha un decoder che possiede 2 linee di input?

```
in base alla
combinazione dei bit
presenti ai suoi ingressi,
attiva una rispettiva
combinazione di bit
sulle linee di uscita. altra slide per approfondimenti
```

#### Cosa si intender per ordinamente Big Endian e Little endian?

```
Sono due modi diversi di scrivere in memoria lo stesso dato,
little endian scrivere all'indirizzo più basso il suo byte meno significativo, mentre big endian fa il contrario.
```

#### Cosa si intende con il termine 'maschera di bit' e in quali casi può essere utile?

```
una maschera di bit è una qualsiasi configurazione di un insieme di bit di lunghezza predefinita.
Le operazione che può essere utile eseguire su una locazione di memoria, sono il setting di uno o più bit, o la verifica del valore di uno o più bit
```

#### Pro e Contro di bus sincroni e asincroni

```
I bus sincroni sono sincronizzati in base al clock della cpu e quindi `e piu facile da realizzare ma si spreca tempo se le istruzioni finiscono prima del ciclo di cock o ci mettono magari 1 ciclo di clock e mezzo. 
Nel bus asincrono invece lo slave esegue il lavoro nel minor tempo possibile poi mette i dati sul bus e il master li legge, tuttavia sono più difficile da realizzare
```

#### Discutere PRo e contro di tecnologie RISC e CISC

```
In CISC si ha un istruction set più ampio --> anche se ognuna di queste istruzioni richiede più cicli di data path.
In RISC  si ha un instruction set più piccolo ma le istruzioni devono essere eseguite in un ciclo di data path o pochi ciclo.
x86 attualmente usa CISC as instruction set but RISC as architectural core.
```

# 2019-01-21

#### Qual è il principio di funzionamento di una stampante laser?

```
Stampanti inchiostro --> CYMK (Cyan,yellow,magenta,blaCK) .
nei modelli piezoelettrici un cristallo opera come tappo che si deforma quando gli si applica una tensione fa uscire una gocciolina. nei modelli termici all'interno di ogni ugello una gocccia di'inchiostro viene riscaldata sino all'ebollizione.

Stampanti laser --> il tamburo viene caricato fino a 1000 volt e ricoperto di materiale fotosensibile.
Tramite uno specchio ottagonale viene fatta passare una luce laser sul tambuero: i punti colpiti dal raggio perdono la carica elettrica

Ruotando il rullo raggiunge il toner e i punti elettricamente carichi attirano il materiale colorante.
Una serie di rulli riscaldati fissa il materiale colorante sulla carta.
Il rullo viene scaricato e poi pulito dai residui.
A colori si usano 4 toner con 4 tamburi
```

#### Che cosa si intende per "tecniche di predizione di salto" e in quali casi possono essere utili?

```
Le architetture con pipeline funzionano molto bene se nel codice non ci sono salti. si possono utilizzare delle tecniche per ottimizzare il pre-fetching uttilizzando le predizioni di salto.
predizione statica : vengono utilizzati criteri di buon senso derivati dallo studio delle abitudini dei programmatori e del comportamento dei compilato. ad esempio assumiamo che tutti i salti all'indietro vengano esegutii (cicli).
predifizone dinamica : vengono mantenute delle statistiche sulla frequenza con cui i recenti salti condizionali sono stati eseguiti, e in base a questa tabella viene eseguita la predizione.
```

#### Descrivere compilatore,assemblatore,linker

```
Compilatore: è un programma che traduce una serie di istruzioni scritte in un linguaggio di alto livello in istruzioni di un'altro linguaggio.
Assemblatore: traduce le istruzioni assembly in linguaggio macchina.
Linker: è il programma che si occupa di collegare i vari moduli (librerie o sottoprogrammi) creando una singola unità eseguibile.
```

#### Cosa è l'arbitraggio del buse, e quali sono le politiche di arbitraggio? 

```
51) Le politiche di arbitraggio del bus sono la soluzione al fatto che più dispositivi possono richiedere il controllo del bus nello stesso momento.
Quindi uno dei due deve aspettare e ciò viene deciso dalle poliche di arbitraggio che può essere centralizzato o distribuito.
Nell'arbitraggio centralizzato è presente un chip arbitro collegato a tutti i dispositivi, quando un dispositivo chiede il controllo del bus l'arbitro attiva un metodo di priorità.
Nell'arbitraggio distribuito non c'è un chip arbitro, vengono utilizzate 16 linee di richiesta.
Ogni dispositivo è collegato a tutte e 16 le linee ed è anche in grando di valutare la sua priorità rispetto agli altri.
```

#### Si spiega la differenza fra "polling" e "interrupt"

```
Il polling e l'interrupt sono due tecniche per monitorare lo stato di una periferica da parte della CPU. Il polling consiste nel controllare in modo periodico, durante un ciclo, lo stato della periferica. Questo però porta a perdita di cicli e quindi di tempo. 
L'interrupt invece viene eseguito dalla periferica che invia un segnale alla CPU la quale può decidere se accettare o rifiutare.
```

#### Che differenza c'è tra la codica numerica del numero 8 e la codifica ascii del numero 8?

```
quando 8 è assegnato a una variable intera avra gli ultimi 4 bit del numero che saranno "1000" che è uguale ad 8 in binario. 
se invece 8 è presente in un documento di testo (txt) o su output (tty) avrà una codifica ascii rapprentabile con il "38h" 
```

# 2019-02-11

#### Elencare i tipi di ROM e per ciascuno indiciare l'utilizzo tipico.

```
PROM: (Programmable ROM) questa memoria può essere scritta una sola volta ma la differenza è che i metodi con cui è scritta sono più semplici e meno dispendionsi. 
EPROM (Erasable PROM) funziona come una PROM ma può essere riscritta usando il laser
EEPROM (Elettracly EPROM), ciascuna delle celle di memoria capace di memorizzare un singolo bit è costituito da due transistor MOS, uno di memoria e uno di accesso. 
La riprogrammazione può essere fatta incircuit e può essere cancellata elettricamente più velocemente della EPROM
```

#### Indicare il tempo richiesto (Come ordine di grandezza) per eseguire ciascuna delle tre fasi necessarie per la lettrue di un settore in un disco magnetico

```
Seek time : tempo per spostare testine sul cilindo desiderato e può essere suddiviso in tre fasi (speed up,coast e slow down).
Average Seek : 8-10 ms 
Track-to-track : 1ms
Full-stroke : 15-20ms

Latency time : rappresenta il tempo necessario affinche il settore interessato all'operazione passo sotto la testina. QUesto fattore è definito dalla velocità del disco che varia da 3600 a 15000 RPM.
Ricordo che 

Traccia : sequenza circloare di bit
Settore : porzione di traccia di dimensione fissa. 
Ed è composto da un preambolo, dati,codice correzione errorii.
Clindro : insimee delle tracce in una data posizione radiale.
```

#### Discutere differenza tra bus PCI e PCI-Express

```
Il bus PCI è un BUS sincrono con 32 linee dati e opera a 33 Mhz.
Le linee dati e indirizzi sono comuni, l'arbitraggio del bus è centralizzato.
Il bus PCIe invece è un bus seriale con connessioni punto a punto ad alta velocità.
Sono possibili collegamenti punto a punto simultanei tra coppie master-slave.
prevede più canali (lanes) indipendenti e si possono usare più canali in parallelo.
```

#### Qual è l'intervallo di numeri interi rappresentabile utilizzando n bit in complemento a 2?

```
negativi --> 2^(n-1)
positivi --> 2^(n-1)-1
```

#### Descrivere le differenza fra parallelismo a "livello di istruzione" e a "livello di processore".

```
Il parallelismo a livello di istruzione consiste nell'eseguire più istruzioni contemporaneamente attraverso tecniche di pipeling e Architetture Superscalari.
Si parla di parallelismo a livello di processore quando lo stesso problema (o processo) è suddiviso in più parti (più thread) che vengono eseguite in modo suddiviso da più CPU.
```

#### A cosa server l'unita floating point in una CPU?

```
Serve a processare informazioni in formato floating point (virgola mobile), mentre la ALU lavora solo con numeri interi.
```

## Es2 

### Cache

```
Ttot = (Nptot*Tc1)+[(Nptot-Nc1)*Tc2]+[(Nptot-Nc1-Nc2)*Tc3]+[(Nptot-Nc1-Nc2-Nc3)*Tram]
```

### Accelerazione 

```
Tf=[(p*Ti)/alfa] + (1-p)*Ti
```

### Tempo esecuzione

```
Tes=Tclock*[sommatoria i=0 ---> n (Ni*CPIi)]
```

