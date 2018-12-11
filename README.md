# cbible
Reading the Bible from CLI

Simple way to get a Bible chunk data from [bible-api.com](https://bible-api.com/) provider and using [cURL](https://github.com/curl/curl) library.

## How to Install

You can install or just build:

```shell
make install
bible john 3:16
```

Output:

```json
{
  "reference": "John 3:16",
  "verses": [
    {
      "book_id": "JHN",
      "book_name": "John",
      "chapter": 3,
      "verse": 16,
      "text": "\nFor God so loved the world, that he gave his one and only Son, that whoever believes in him should not perish, but have eternal life.\n\n"
    }
  ],
  "text": "\nFor God so loved the world, that he gave his one and only Son, that whoever believes in him should not perish, but have eternal life.\n\n",
  "translation_id": "web",
  "translation_name": "World English Bible",
  "translation_note": "Public Domain"
}
```
