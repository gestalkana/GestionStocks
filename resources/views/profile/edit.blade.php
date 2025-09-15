@extends('layouts.app')

@section('title', 'Mon Profil')
@section('Page-title', 'Profil utilisateur')

@section('content')
<div class="row justify-content-center">
    <div class="col-md-10 col-lg-8">

        @if(session('success'))
            <div class="alert alert-success alert-dismissible fade show small" role="alert">
                {{ session('success') }}
                <button type="button" class="btn-close btn-sm" data-bs-dismiss="alert" aria-label="Close"></button>
            </div>
        @endif

        <div class="card border-0 shadow-sm rounded-4">
            <div class="card-body p-4">

                <div class="d-flex align-items-center mb-4">
                    <img src="https://ui-avatars.com/api/?name={{ urlencode($user->name) }}&size=64" alt="Avatar"
                         class="rounded-circle me-3 border" width="50" height="50">
                    <div>
                        <h5 class="mb-0">{{ $user->name }}</h5>
                        <small class="text-muted">{{ $user->email }}</small>
                    </div>
                </div>

                <!-- <form action="{{ route('profile.update') }}" method="POST" class="small"> -->
                <form id="profileForm" action="{{ route('profile.update') }}" method="POST" class="small">

                    @csrf

                    <!-- Nom -->
                    <div class="mb-2">
                        <label for="name" class="form-label">Nom</label>
                        <input type="text" id="name" name="name"
                               class="form-control form-control-sm @error('name') is-invalid @enderror"
                               value="{{ old('name', $user->name) }}" required>
                        @error('name') <div class="invalid-feedback">{{ $message }}</div> @enderror
                    </div>

                    <!-- Email -->
                    <div class="mb-2">
                        <label for="email" class="form-label">Email</label>
                        <input type="email" id="email" name="email"
                               class="form-control form-control-sm @error('email') is-invalid @enderror"
                               value="{{ old('email', $user->email) }}" required>
                        @error('email') <div class="invalid-feedback">{{ $message }}</div> @enderror
                    </div>

                    <hr class="my-3">

                    <h6 class="text-muted mb-3">
                        <i class="bi bi-lock-fill me-1"></i>Changer le mot de passe <small>(optionnel)</small>
                    </h6>

                    <!-- Mot de passe actuel -->
                   <input type="hidden" name="current_password" id="current_password_hidden" value="">

                    <!-- Nouveau mot de passe -->
                    <div class="mb-2">
                        <label for="password" class="form-label">Nouveau mot de passe</label>
                        <input type="password" id="password" name="password"
                               class="form-control form-control-sm @error('password') is-invalid @enderror">
                        @error('password') <div class="invalid-feedback">{{ $message }}</div> @enderror
                    </div>

                    <!-- Confirmation -->
                    <div class="mb-3">
                        <label for="password_confirmation" class="form-label">Confirmer le mot de passe</label>
                        <input type="password" id="password_confirmation" name="password_confirmation"
                               class="form-control form-control-sm">
                    </div>

                    <div class="d-flex justify-content-end">
                        <button type="button" id="openConfirmModal" class="btn btn-sm btn-success px-3">
                            <i class="bi bi-save me-1"></i> Enregistrer
                        </button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>
@include('profile.modalConfimationPassword')
@endsection
