@extends('layouts.guest')

@section('title', 'Connexion')

@push('styles')
<style>
    /* Illustration animée */
    .login-illustration {
        position: relative;
        background: #0c6279; /* couleur fallback */
    }
    #particles-js {
        position: absolute;
        width: 100%;
        height: 100%;
        top: 0;
        left: 0;
    }

    /* Bouton principal */
    .btn-accent {
        background: var(--accent);
        color: #fff;
    }
    .btn-accent:hover,
    .btn-accent:focus {
        background: #0a5060;
        color: #fff;
    }
   h1.stylish-title {
    font-weight: 700;
    font-size: 2.2rem;
    display: inline-block;
    position: relative;

    /* Texte avec dégradé animé */
    background: linear-gradient(90deg, #0c6279, #00bcd4, #0c6279);
    background-size: 200% auto;
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    animation: gradient-move 3s linear infinite;
}

/* Animation du dégradé */
@keyframes gradient-move {
    0% { background-position: 0% }
    100% { background-position: 200% }
}

h1.stylish-title::after {
    content: "";
    position: absolute;
    left: 50%;             /* centre horizontalement */
    bottom: -8px;
    width: 100%;
    height: 4px;
    background: linear-gradient(90deg, #0c6279, #00bcd4);
    transform: translateX(-50%) scaleX(0); /* translate pour centrer */
    transform-origin: center;
    transition: transform 0.6s ease;
    border-radius: 4px;
}
h1.stylish-title:hover::after {
    transform: translateX(-50%) scaleX(1);
}

</style>
@endpush

@section('content')
<div class="card shadow-sm border-0 rounded-4 overflow-hidden" style="max-width: 880px; width:100%;">
    <div class="row g-0">
        {{-- Colonne illustration animée --}}
        <div class="col-md-6 d-none d-md-block login-illustration">
            <div id="particles-js"></div>
        </div>

        {{-- Colonne formulaire --}}
        <div class="col-12 col-md-6 p-5">
            <div class="d-flex justify-content-center mb-4">
                <h1 class="stylish-title">Connexion</h1>
            </div>

  

            <form method="POST" action="{{ route('login') }}">
                @csrf

                {{-- Adresse e-mail --}}
                <div class="mb-3">
                    <label for="email" class="form-label">Adresse e-mail</label>
                    <input  id="email"
                            type="email"
                            name="email"
                            value="{{ old('email') }}"
                            required
                            autofocus
                            class="form-control form-control-lg @error('email') is-invalid @enderror">
                    @error('email') <div class="invalid-feedback">{{ $message }}</div> @enderror
                </div>

                {{-- Mot de passe --}}
                <div class="mb-3">
                    <label for="password" class="form-label">Mot de passe</label>
                    <input  id="password"
                            type="password"
                            name="password"
                            required
                            class="form-control form-control-lg @error('password') is-invalid @enderror">
                    @error('password') <div class="invalid-feedback">{{ $message }}</div> @enderror
                </div>

                {{-- Souvenez-vous de moi + lien mot de passe --}}
                <div class="d-flex justify-content-between align-items-center mb-4">
                    <div class="form-check">
                        <input  id="remember"
                                class="form-check-input"
                                type="checkbox"
                                name="remember">
                        <label class="form-check-label small" for="remember">Rester connecté</label>
                    </div>
                    <a href="{{-- route('password.request') --}}" class="small text-decoration-none">
                        Mot de passe oublié ?
                    </a>
                </div>

                {{-- Bouton de connexion --}}
                <button type="submit" class="btn btn-accent w-100 py-2">Se connecter</button>
            </form>
        </div>
    </div>
</div>
@endsection

@push('scripts')
    {{-- Particles.js --}}
    <script src="https://cdn.jsdelivr.net/npm/particles.js@2.0.0/particles.min.js"></script>
    <script>
        particlesJS("particles-js", {
            "particles": {
                "number": { "value": 60 },
                "color": { "value": "#ffffff" },
                "shape": { "type": "circle" },
                "opacity": { "value": 0.5 },
                "size": { "value": 3 },
                "line_linked": { "enable": true, "color": "#ffffff" },
                "move": { "enable": true, "speed": 2 }
            }
        });
    </script>
@endpush
