@extends('layouts.guest')

@section('title', 'Connexion')

@push('styles')
<style>
    /* Illustration (optionnelle) */
    .login-illustration {
        background: url('{{ asset('images/stock-login.jpg') }}') center/cover;
    }
    /* Bouton principal à la couleur d’accent */
    .btn-accent {
        background: var(--accent);
        color: #fff;
    }
    .btn-accent:hover,
    .btn-accent:focus {
        background: #0c6279;
        color: #fff;
    }
</style>
@endpush

@section('content')
<div class="card shadow-sm border-0 rounded-4 overflow-hidden" style="max-width: 880px; width:100%;">
    <div class="row g-0">
        {{-- Colonne illustration (cachée sur mobiles) --}}
        <div class="col-md-6 d-none d-md-block login-illustration"></div>

        {{-- Colonne formulaire --}}
        <div class="col-12 col-md-6 p-5">
            <h1 class="mb-4 text-center txt-primary fw-semibold">Connexion</h1>

            <form method="POST" action="{{ route('login') }}">
                @csrf

                {{-- Adresse e‑mail --}}
                <div class="mb-3">
                    <label for="email" class="form-label">Adresse e‑mail</label>
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

                {{-- Souvenez‑vous de moi + lien mot de passe --}}
                <div class="d-flex justify-content-between align-items-center mb-4">
                    <div class="form-check">
                        <input  id="remember"
                                class="form-check-input"
                                type="checkbox"
                                name="remember">
                        <label class="form-check-label small" for="remember">Rester connecté</label>
                    </div>
                    <a href="{{ route('password.request') }}" class="small text-decoration-none">
                        Mot de passe oublié ?
                    </a>
                </div>

                {{-- Bouton de connexion --}}
                <button type="submit" class="btn btn-accent w-100 py-2">Se connecter</button>
            </form>
        </div>
    </div>
</div>
@endsection
