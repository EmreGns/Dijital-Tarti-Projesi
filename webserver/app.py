from flask import Flask, request, render_template_string

app = Flask(__name__)

latest_weight = "Henüz veri yok"

@app.route('/data', methods=['POST'])
def receive_data():
    global latest_weight
    weight = request.form.get('weight')
    if weight:
        latest_weight = f"{weight}"
        print(f"Gelen ağırlık verisi: {latest_weight} gram")
        return "Veri alındı", 200
    else:
        return "Veri bulunamadı", 400

@app.route('/')
def show_weight():
    return render_template_string('''
        <!DOCTYPE html>
        <html>
        <head>
            <title>Canlı Ağırlık Verisi</title>
            <meta http-equiv="refresh" content="1">
            <style>
                body { font-family: Arial; text-align: center; margin-top: 50px; }
                h1 { font-size: 48px; }
            </style>
        </head>
        <body>
            <h1>Ağırlık: {{ weight }} gram</h1>
            <p>Sayfa 1 saniyede bir otomatik yenilenir.</p>
        </body>
        </html>
    ''', weight=latest_weight)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
