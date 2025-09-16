# Proyecto TP4 - IDS

Estudiante: Laura Andrea Moreno Rodriguez 

Este proyecto contiene código en **C** con sistema de compilación basado en `make` y verificación automática de formato con `pre-commit` y `clang-format`.

## 🚀 Clonar el repositorio

```bash
git clone git@github.com:lalumoreno/ids-tp4.git
cd ids-tp4
```

## 🔧 Configuración inicial
Instalar los hooks de **pre-commit**:

```bash
pre-commit install
```

De esta forma, cada vez que realices un commit se ejecutará automáticamente `clang-format` para asegurar un estilo de código consistente.

## 🛠️ Compilación

Para compilar el proyecto:

```bash
make all
```

El artefacto generado estará disponible en:

```
build/program
```

## 🧹 Limpiar

Para eliminar los binarios y objetos generados:

```bash
make clean
```

## 📖 Documentación (opcional)

Si tienes instalado **Doxygen**, puedes generar la documentación con:

```bash
doxygen Doxyfile
```

y abrir en el navegador:

```
docs/html/index.html
```
