#ifndef _INTELLINO_AS_H
#define _INTELLINO_AS_H

#define INTELLINO_SETBASE(vecaddr, cataddr) \
    asm volatile ( "add  $k0,   %0, $0" ::"r"(vecaddr)); \
    asm volatile ( "add  $k1,   %0, $0" ::"r"(cataddr))

#define INTELLINO_TRAIN(num) \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+  0)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+  4)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+  8)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 12)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 16)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 20)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 24)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 28)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 32)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 36)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 40)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 44)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 48)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 52)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 56)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 60)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 64)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 68)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 72)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 76)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 80)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 84)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 88)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 92)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+ 96)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+100)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+104)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+108)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+112)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+116)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+120)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+124)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+128)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+132)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+136)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+140)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+144)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+148)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+152)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+156)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+160)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+164)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+168)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+172)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+176)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+180)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+184)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+188)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+192)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+196)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+200)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+204)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+208)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+212)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+216)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+220)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+224)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+228)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+232)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+236)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+240)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+244)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+248)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+252)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+256)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+260)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+264)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+268)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+272)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+276)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+280)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+284)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+288)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+292)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+296)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+300)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+304)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+308)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+312)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+316)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+320)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+324)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+328)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+332)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+336)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+340)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+344)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+348)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+352)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+356)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+360)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+364)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+368)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+372)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+376)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+380)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+384)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+388)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+392)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+396)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+400)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+404)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+408)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+412)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+416)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+420)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+424)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+428)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+432)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+436)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+440)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+444)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+448)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+452)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+456)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+460)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+464)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+468)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+472)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+476)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+480)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+484)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+488)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+492)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+496)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+500)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+504)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+508)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+512)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+516)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+520)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+524)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+528)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+532)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+536)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+540)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+544)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+548)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+552)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+556)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+560)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+564)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+568)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+572)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+576)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+580)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+584)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+588)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+592)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+596)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+600)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+604)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+608)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+612)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+616)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+620)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+624)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+628)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+632)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+636)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+640)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+644)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+648)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+652)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+656)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+660)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+664)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+668)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+672)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+676)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+680)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+684)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+688)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+692)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+696)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+700)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+704)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+708)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+712)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+716)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+720)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+724)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+728)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+732)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+736)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+740)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+744)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+748)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+752)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+756)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+760)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+764)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+768)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+772)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+776)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+780)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+784)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+788)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+792)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+796)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+800)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+804)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+808)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+812)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+816)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+820)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+824)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+828)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+832)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+836)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+840)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+844)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+848)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+852)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+856)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+860)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+864)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+868)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+872)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+876)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+880)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+884)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+888)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+892)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+896)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+900)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+904)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+908)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+912)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+916)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+920)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+924)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+928)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+932)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+936)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+940)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+944)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+948)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+952)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+956)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+960)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+964)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+968)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+972)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+976)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+980)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+984)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+988)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+992)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+996)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+1000)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+1004)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+1008)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+1012)); \
    asm volatile ( "lwc2 comp,  %0($k0)"::"i"(num*1024+1016)); \
    asm volatile ( "lwc2 lcomp, %0($k0)"::"i"(num*1024+1020)); \
    asm volatile ( "lwc2 cat,   %0($k1)"::"i"(num*4))

#endif
