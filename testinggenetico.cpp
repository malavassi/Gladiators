#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Generacion.h"
#include "LinkedList.h"
#include "Gladiator.h"
#include "Poblacion.h"
#include "Simulacion.h"

struct PruebaPoblacion: testing::Test{
    Poblacion* poblacion;
    PruebaPoblacion(){
        poblacion = new Poblacion('A');
    }
    ~PruebaPoblacion(){
        delete poblacion;
    }
};

struct PruebaSimulacion: testing::Test{
    Simulacion* simulacion;
    PruebaSimulacion(){
        simulacion = new Simulacion();
    }
};

struct PruebaGeneracion: testing::Test{
    Generacion* generacion;
    Generacion* rGeneracion;
    LinkedList<Gladiator*>* glads = new LinkedList<Gladiator*>();
    PruebaGeneracion(){
        generacion = new Generacion(0);
        for(int i=0;i<20;i++){
            glads->push_back(new Gladiator(1*i,2*i,3*i,4*i));
        }
        rGeneracion = new Generacion(*glads, 1);
    }
    ~PruebaGeneracion(){
        delete generacion;
    }
};

struct PruebaGladiador: testing::Test{
    Gladiator* Foolglad;
    Gladiator* attrGlad;
    PruebaGladiador(){
        Foolglad = new Gladiator();
        attrGlad = new Gladiator(1,2,3,4);
    }
};

// Pruebas de gladiador
TEST_F(PruebaGladiador, initialProvidedArguments){
    EXPECT_EQ(1,attrGlad->getIQemocional());
    EXPECT_EQ(2,attrGlad->getCondicionFisica());
    EXPECT_EQ(3,attrGlad->getFuerzaTSuperior());
    EXPECT_EQ(4, attrGlad->getFuerzaTInferior());
}

TEST_F(PruebaGladiador, initialCalculatedArguments){
    EXPECT_EQ(2,Foolglad->getIdUnico());
    EXPECT_EQ(3, attrGlad->getIdUnico());
    EXPECT_EQ(4, attrGlad->getGeneracionesEsperadas());
    EXPECT_EQ(0, attrGlad->getProbabilidadSupervivencia());
    EXPECT_EQ(0, attrGlad->getEdad());
    EXPECT_EQ(0, attrGlad->getResistencia());
    EXPECT_EQ(nullptr,attrGlad->getPadre1());
    EXPECT_EQ(nullptr,attrGlad->getPadre2());
    EXPECT_EQ(1,attrGlad->getAttr(0));
    EXPECT_EQ(3,attrGlad->getAttr(1));
    EXPECT_EQ(4,attrGlad->getAttr(2));
    EXPECT_EQ(2,attrGlad->getAttr(3));
}

TEST_F(PruebaGladiador, aumentarEdad){
    attrGlad->avanzarEdad();
    EXPECT_EQ(20,attrGlad->getEdad());
}


// Pruebas generacion
TEST_F(PruebaGeneracion, parametrosIniciales){
    EXPECT_EQ(0,generacion->getEdad());
    EXPECT_EQ(20,generacion->getGladiadores().getSize());
    EXPECT_EQ(0,generacion->getNumero());
    EXPECT_EQ(0,generacion->getPromedioSupervivencia());
}

TEST_F(PruebaGeneracion, modificarEdad){
    rGeneracion->avanzarEdad();
    for(int i=0;i<rGeneracion->getGladiadores().getSize();i++){
        EXPECT_EQ(20, rGeneracion->getGladiadores().getElemento(i)->getData()->getEdad());
    }
    EXPECT_EQ(20, rGeneracion->getEdad());
}


// Pruebas poblacion
TEST_F(PruebaPoblacion, parametrosIniciales){
    EXPECT_FALSE(poblacion->getGeneraciones().getHead()==nullptr);
    Generacion* actual = poblacion->getGeneraciones().getHead()->getData();
    EXPECT_EQ(20, actual->getEdad());
}

TEST_F(PruebaPoblacion, fitness){
    Generacion* actual = poblacion->getGeneraciones().getHead()->getData();
    EXPECT_TRUE(actual->getGladiadores().getHead()->getData()->getResistencia()>0);
    EXPECT_EQ(actual->getGladiadores().getHead()->getData()->getProbabilidadSupervivencia(),actual->getGladiadores().getHead()->getData()->getResistencia());
}

TEST_F(PruebaPoblacion, seleccion){
    poblacion->seleccion();
    EXPECT_FALSE(nullptr==poblacion->getElegido());
}

TEST_F(PruebaPoblacion, reproducion){
    poblacion->reproduccion();
    EXPECT_EQ(2, poblacion->getGeneraciones().getSize());
    EXPECT_EQ(20, poblacion->getGeneraciones().getElemento(0)->getData()->getGladiadores().getSize());
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
